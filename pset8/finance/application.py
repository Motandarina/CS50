import os
import time

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    infos=db.execute("SELECT symbol,shares FROM purchases WHERE uid=:id",id=session["user_id"])
    sum=0
    if not infos:
        infos=[{'symbol':'无','name':'无','prices':0,'shares':0,'sum':0}]
    else:
        for item in infos:
            quote=lookup(item['symbol'])
            item['name']=quote['name']
            item['prices']=quote['price']
            stock_cash=quote['price'] * item['shares']
            sum+=stock_cash
            item['stock_cash']=usd(stock_cash)
    cash=db.execute("SELECT cash FROM users WHERE id=:id",id=session["user_id"])
    print(cash)
    print(infos)
    total=usd( sum + cash[0]['cash'])
    cash[0]['cash']=usd(cash[0]['cash'])
    return render_template("index.html",infos=infos,cash=cash,total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method=="POST":
       uid=session["user_id"]
       symbol=request.form.get("symbol")
       shares=request.form.get("shares")
       if not symbol:
           return apology("Please input a symbol",403)
       if not shares:
           return apology("Please input shares",403)
       quote=lookup(symbol)
       if not quote:
           return apology("symbol not found",403)
       name=quote['name']
       #check if there is enough money
       cresult=db.execute("SELECT cash FROM users WHERE id=:id",id=uid)
       shares=int(shares)
       prices=quote['price']
       #print(type(shares))
       #print(type(prices))
       cost=shares * prices

       if cresult[0]['cash'] >= cost:
           #update cash
           db.execute("UPDATE users SET cash = cash - :cost WHERE id=:id",cost=cost,id=uid)
           #logging history
           db.execute("INSERT INTO history (uid,symbol,name,shares,prices,time) VALUES(:uid,:symbol,:name,:shares,:prices,:time)",uid=uid,symbol=symbol,name=name,shares=shares,prices=prices,time=time.time())

           #insert new stock shares
           presult=db.execute("SELECT shares FROM purchases WHERE uid=:id AND symbol=:symbol",id=uid,symbol=symbol)
           if not presult:
               db.execute("INSERT  INTO purchases (uid,symbol,shares) VALUES(:uid,:symbol,:shares)",uid=uid,symbol=symbol,shares=shares)
           #update stock shares
           else:
               db.execute("UPDATE purchases SET shares=shares+:shares WHERE uid=:id AND symbol=:symbol",id=uid,symbol=symbol,shares=shares)
       else:
           return apology("You don't have enough money!",403)
       #return to index page
       return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/check", methods=["GET"])
def check():
    """Return true if username available, else false, in JSON format"""
    username=request.args.get("username")
    result=db.execute("SELECT id FROM users WHERE username=:username",username=username)
    if len(username) >= 1 and not result:
        return jsonify([{username: True}])
    else:
        return jsonify([{username: False}])


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    """Show portfolio of stocks"""
    logs=db.execute("SELECT * FROM history WHERE uid=:uid",uid=session['user_id'])
    if logs:
        for log in logs:
            log['total']=usd(log['prices']*log['shares'])
            log['time']=time.asctime( time.localtime(log['time']) )
    print(logs)
    return render_template("history.html",logs=logs)



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
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]
        session["user_name"] = request.form.get("username")

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
    if request.method=="POST":
        symbol=request.form.get("symbol")
        quote=lookup(symbol)
        print(quote)
        if not quote:
            return apology("symbol not found",403)
        quote['price']=usd(quote['price'])
        return render_template("quoted.html",quote=quote)
    else:
        return render_template("quote.html")
    return apology("TODO")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method=="POST":
        username=request.form.get("username")
        password=request.form.get("password1")
        password1=request.form.get("password2")
        if not username:
            return apology("missing username!", 403)
        elif not password or not password1:
            return apology("missing password!",403)
        elif not password == password1:
            return apology("password should be the same!",403)

        #hash password
        hash=generate_password_hash(password)

        #insert user into database
        result=db.execute("INSERT INTO users(username,hash) VALUES(:username,:hash)",username=username,hash=hash)
        if not result:
            return apology("username already used by others",403)

        # Query database for user_id
        rows = db.execute("SELECT id FROM users WHERE username = :username",
                          username=username)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    else:
        return render_template("register.html")

@app.route("/account", methods=["GET", "POST"])
@login_required
def account():
    if request.method=="POST":
        username=request.form.get("username")
        password=request.form.get("password1")
        password1=request.form.get("password2")
        password2=request.form.get("password3")
        if not username:
            return apology("missing username!", 403)
        if not password or not password1 or not password2:
            return apology("missing password!",403)

        # Query database for password
        rows=db.execute("SELECT hash FROM users WHERE username = :username",
                          username=username)
        # Ensure  password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], password):
            return apology("invalid password", 403)

        #Check if new passwords are the same
        if not password1 == password2:
            return apology("password should be the same!",403)

        #hash password
        hash=generate_password_hash(password1)

        #insert user into database
        result=db.execute("UPDATE users SET hash=:hash WHERE username=:username" ,username=username,hash=hash)

        #ask user to relogin

        # Redirect user to home page
        return redirect("/login")
    else:
        return render_template("account.html")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    uid=session["user_id"]

    if request.method=="POST":
        #get post values
        symbol=request.form.get("symbol")
        shares=request.form.get("shares")

        #check empty fields
        if not symbol:
            return apology("symbol should not be empty!",403)
        if not shares:
            return apology("shares should not be empty!",403)
        #check if shares is a positive integer
        if not shares.isdigit() or int(shares)<=0:
            return apology("shares should be positive integer!",403)

        #check shares cannot exceed max limits
        share_max=db.execute("SELECT shares FROM purchases WHERE uid=:uid AND symbol=:symbol",uid=uid,symbol=symbol)
        s_m=share_max[0]['shares']
        if int(shares)> s_m:
            return apology(f"only { s_m } shares left",403)

        #update database tables(user{cash},purchase(symbol,shares),history)

        #update user(cash)
        quote=lookup(symbol)
        name=quote['name']
        gain=quote["price"]*int(shares)
        db.execute("UPDATE users SET cash=cash + :gain WHERE id=:id",id=uid,gain=gain)

        #update purchase(symbol,shares)
        if int(shares)==s_m:
            db.execute("DELETE FROM purchases WHERE uid=:uid AND symbol=:symbol",uid=uid,symbol=symbol)
        else:
            db.execute("UPDATE purchases SET shares=shares-:shares WHERE uid=:uid AND symbol=:symbol",shares=shares,uid=uid,symbol=symbol)

        #logging history
        db.execute("INSERT INTO history (uid,symbol,name,shares,prices,time) VALUES(:uid,:symbol,:name,:shares,:prices,:time)",uid=uid,symbol=symbol,name=name,shares=-int(shares),prices=quote["price"],time=time.time())
        return redirect("/")
    else:
        results=db.execute("SELECT symbol,shares FROM purchases WHERE uid=:uid",uid= session["user_id"] )
        print(results)
        return render_template("sell.html",results=results)


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
