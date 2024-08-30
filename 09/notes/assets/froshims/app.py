from flask import Flask, render_template, request, redirect

app = Flask(__name__)

SPORTS = ["Basketball", "Ultimate Frisbee", "Football"]
REGISTRANTS = {}


@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)


@app.route("/register", methods=["POST"])
def register():
    if not request.form.get("name"):
        return render_template("failure.html", msg="Name not provided."), 400

    if not request.form.getlist("sport"):
        return render_template("failure.html", msg="No sport provided"), 400

    for sport in request.form.getlist("sport"):
        if sport not in SPORTS:
            return render_template("failure.html", msg=f"Sport: {sport} is not allowed."), 400

    REGISTRANTS[request.form.get("name")] = sorted(request.form.getlist("sport"))
    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    return render_template("registrants.html", registrants=REGISTRANTS)
