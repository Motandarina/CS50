from flask import request,Flask,render_template

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html", name=request.args.get("name","world"))