from flask import Flask,redirect,render_template,request
from cs50 import SQL

#config app
app = Flask(__name__)

#load db
db = SQL("sqlite:///froshims.db")

@app.route("/")
def index():
    q=request.args.get("q")
    rows = db.execute(f"SELECT * FROM registrants where name = '{ q }' ")
    return render_template("index.html",rows=rows)

