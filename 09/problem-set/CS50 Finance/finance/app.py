import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # Get stocks data
    balance = round(
        db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0][
            "cash"
        ],
        2,
    )

    total = balance
    portfolio = db.execute(
        "SELECT symbol, share_count, price_per_stock, created_at FROM transactions WHERE user_id = ?",
        session["user_id"],
    )
    for stock in portfolio:
        stock["value"] = round(stock["share_count"] * stock["price_per_stock"], 2)
        total += stock["value"]
        stock["current_price"] = lookup(stock["symbol"])["price"]

    return render_template(
        "index.html", portfolio=portfolio, balance=balance, total=total
    )


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        # Check symbol exists and isn't blank
        symbol = request.form.get("symbol")
        if not symbol or not symbol.strip():
            return apology(
                f"must provide symbol{', symbol is blank' if symbol else ''}", 400
            )
        stock = lookup(symbol)
        if not stock:
            return apology(f"Symbol {symbol} not found", 400)

        # Check shares
        shares = request.form.get("shares")
        if not shares.isnumeric() or int(shares) <= 0:
            return apology(f"shares: {shares} is not a positive integer", 400)
        shares = int(shares)

        user_id = session["user_id"]
        balance = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[
            0
        ]["cash"]
        requested_price = stock["price"] * shares

        if balance - requested_price > 0:
            db.execute(
                "UPDATE users SET cash = ? WHERE id = ?",
                balance - requested_price,
                user_id,
            )
            db.execute(
                "INSERT INTO transactions (user_id, symbol, share_count, price_per_stock) VALUES(?, ?, ?, ?)",
                user_id,
                stock["symbol"],
                shares,
                stock["price"],
            )
        else:
            return apology(
                "Error, user does not have enough funds to complete purchase", 400
            )

        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        # Check if symbol was requested
        symbol = request.form.get("symbol")
        if not symbol or not symbol.strip():
            return apology(
                f"must provide symbol{', symbol is blank' if symbol else ''}", 400
            )

        data = lookup(symbol)
        if data:
            symbol = data["symbol"]
            price = data["price"]
            return render_template("quoted.html", symbol=symbol, price=price)
        else:
            return apology(f"Symbol {symbol} not found", 400)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        # Check username is not blank or whitespace
        username = request.form.get("username")
        if not username or not username.strip():
            return apology(
                f"must provide username{', username blank' if username else ''}", 400
            )

        # Check passwords are not blank or whitespace
        passwords = [
            request.form.get("password"),
            request.form.get("confirmation"),
        ]
        for password in passwords:
            if not password or not password.strip():
                return apology(
                    f"must provide password{', password is blank' if password else ''}",
                    400,
                )
        # Check passwords match
        if passwords[0] != passwords[1]:
            return apology("passwords do not match", 400)
        else:
            password = passwords[0]

        # Register user
        usernames_query = db.execute(
            "SELECT username FROM users WHERE username = ?", username
        )
        if len(usernames_query) != 0:
            return apology(f"username {username} already exists.", 400)
        else:
            registration = db.execute(
                "INSERT INTO users (username, hash) VALUES(?, ?)",
                username,
                generate_password_hash(password),
            )
            return redirect("/login")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
