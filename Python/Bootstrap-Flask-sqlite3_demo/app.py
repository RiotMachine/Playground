import sqlite3
from flask import Flask, flash, g, render_template, request
app = Flask(__name__)

# Init
app.config["SECRET_KEY"] = "dummy"

DB_LOCATION = "./tickets.db"

CATEGORY = [
    "Device request",
    "Password help",
    "Connectivity issue",
]

# Helpers
## Following Flask documentation for built-in SQLite3 support
## https://flask.palletsprojects.com/en/stable/patterns/sqlite3/
def dbOpenDict():
    con = getattr(g, '_database', None)
    if con is None:
        con = g._database = sqlite3.connect(DB_LOCATION, autocommit=True)
        con.row_factory = sqlite3.Row
    return con

### jen je cesky jen
def dbQuery(query, args=(), jen=False):
    cur = dbOpenDict().execute(query, args)
    query = cur.fetchall()
    cur.close()
    return (query[0] if query else None) if jen else query


# Routes
@app.teardown_appcontext
def close_connection(exception):
    con = getattr(g, '_database', None)
    if con is not None:
        con.close()

@app.route("/", methods=["GET", "POST"])
def ticketing_page():
    if request.method == "POST":
        email    = request.form.get("email")
        category = request.form.get("category")
        freetext = request.form.get("freetext")
        ticket_number = dbQuery("INSERT INTO ticket (user_email, category, freetext) "
                        "VALUES (?, ?, ?) "
                        "RETURNING id",
                        [email, category, freetext], jen=True)['id']
        ticket_string = f"Success! Your ticket number is {ticket_number}"
        flash(ticket_string)
    return render_template("ticket_form.html", categories = CATEGORY)