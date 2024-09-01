from datetime import datetime
from flask import Flask, g, redirect, render_template, request
import sqlite3

app = Flask(__name__)

SPORTS = ["Basketball", "Ultimate Frisbee", "Football"]

DATABASE = "./registransts.db"

def connect_db():
    db = getattr(g, "_database", None)
    if db is None:
        db = g._database = sqlite3.connect(DATABASE)
        db.row_factory = sqlite3.Row
    return db

def query_db(query, args=(), one=False):
    con = connect_db()
    cur = con.execute(query, args)
    res = cur.fetchall()
    con.commit()
    cur.close()
    return (res[0] if res else None) if one else res

@app.teardown_appcontext
def close_connection(exception):
    db = getattr(g, "_database", None)
    if db is not None:
        db.close()

def init_db():
    with app.app_context():
        db = connect_db()
        with app.open_resource('schema.sql', mode='r') as f:
            db.cursor().executescript(f.read())
        db.commit()

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)


@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    if not name:
        return render_template("failure.html", msg="Name not provided."), 400

    sports = request.form.getlist("sport")
    if not sports:
        return render_template("failure.html", msg="No sport provided"), 400

    for sport in sports:
        if sport not in SPORTS:
            return render_template("failure.html", msg=f"Sport: {sport} is not allowed."), 400

    # REGISTRANTS[request.form.get("name")] = sorted(request.form.getlist("sport"))
    for sport in sports:
        app.logger.debug("Trying to save: name: %s, sport: %s", name, sport)
        app.logger.debug("Name Type: %s, Sport Type: %s", type(name), type(sport))
        query_db("INSERT INTO registrations (name, sport) VALUES (?, ?)", (name, sport))

    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    registrants_sql = query_db("SELECT name, sport, created_at FROM registrations")
    registrants = []
    for row in registrants_sql:
        registrants.append({
            "name": row['name'],
            "sport": row['sport'],
            "created_at": datetime.strptime(row['created_at'], "%Y-%m-%d %H:%M:%S").strftime("%B %d, %Y %I:%M %p")
        })
    return render_template("registrants.html", registrants=registrants)
