from flask import request,Flask,render_template

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")


@app.route("/register",methods=["POST"])
def register():
    if not request.form.get("name") or not request.form.get("dorm"):
        return render_template("failure.html")
    else:
        return render_template("success.html")