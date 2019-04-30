from flask import redirect,request,Flask,render_template,jsonify

# Configure app
app = Flask(__name__)


# load words
words=[]
with open("large","r") as file:
    for line in file.readlines():
        words.append(line.rstrip())


@app.route("/")
def index():
    return render_template("index.html")

@app.route("/search",methods=["POST","GET"])
def search():
    key=request.args.get("q")
    res=[word for word in words if word.startswith(key)]
    return jsonify(res)

