import cs50
import csv


from flask import Flask, abort,jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")


@app.route("/form", methods=["POST"])
def post_form():
    """
    writes the form’s values to a new row in survey.csv using csv.writer or csv.DictWriter, and

    redirects the user to /sheet.
    """
    #check fields
    #names=["firstName","lastName","userName","sex","city","state","zip","education","agreementCheck"]
    names=["firstName","lastName","userName","sex","city","state","zip","education"]
    for name in names:
        if not request.form.get(name):
            msg="error 400, missing "+name
            return render_template("error.html", msg=msg)
    #get fields
    raw=[]
    for name in names:
        raw.append(request.form.get(name))

    with open("survey.csv","a") as csvfile:
        writer=csv.writer(csvfile)
        writer.writerow(tuple(raw))
    csvfile.close()
    return redirect("/sheet")



@app.route("/sheet", methods=["GET"])
def get_sheet():
    i=1
    with open("survey.csv","r") as csvfile:
        reader=csv.reader(csvfile)
        info=list(reader)
    return render_template("sheet.html",info=info,i=i)


@app.route("/form", methods=["POST"])
def errorhandler(error):
    """Handle errors"""
    return render_template("error.html", error=error), error.code
