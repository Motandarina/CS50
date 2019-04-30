from flask import redirect,request,Flask,render_template
import csv

# Configure app
app = Flask(__name__)


# Registered students
#students=[]

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/registered")
def registered():
    with open("registered.csv","r") as csvfile:
        reader = csv.DictReader(csvfile)
        students = list(reader)
        print(students)
    return render_template("registered.html",students=students)



@app.route("/register",methods=["POST"])
def register():
    name=request.form.get("name")
    dorm=request.form.get("dorm")
    if not name or not dorm:
        return render_template("failure.html")
    with open("registered.csv","a") as csvfile:
        fieldnames=["name","dorm"]
        writer=csv.DictWriter(csvfile,fieldnames=fieldnames)
        writer.writerow({"name":name,"dorm":dorm})
    #csvfile.close()
    return render_template("success.html")



