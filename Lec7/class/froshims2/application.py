from flask import request,Flask,render_template
import smtplib
from email import encoders
from email.header import Header
from email.mime.text import MIMEText
from email.utils import parseaddr, formataddr

def _format_addr(s):
    name, addr = parseaddr(s)
    return formataddr((Header(name, 'utf-8').encode(), addr))

# Configure app
app = Flask(__name__)


# Registered students
students=[]

@app.route("/")
def index():
    return render_template("index.html")
@app.route("/registrants")
def registrants():
    return render_template("registrants.html",students=students)


@app.route("/register",methods=["POST"])
def register():
    name=request.form.get("name")
    dorm=request.form.get("dorm")
    toaddr=request.form.get("email")
    #fromaddr="snowlts@163.com"
    #server="smtp.163.com"
    fromaddr="XXXXXX"
    server="smtp.gmail.com"
    #port=465
    port=587
    #port=25
    username="XXXXXX@gmail.com"
    password="XXXXXX"

    if not name or not dorm or not toaddr:
        return render_template("failure.html")
    #msg = MIMEText('You are registered!', 'plain', 'utf-8')
    #msg['From'] = _format_addr('Python爱好者 <%s>' % fromaddr)
    #msg['To'] = _format_addr('管理员 <%s>' % toaddr)
    #msg['Subject'] = Header('来自SMTP的问候……', 'utf-8').encode()
    msg="yes,you are registered!"
    server=smtplib.SMTP(server,port)
    server.set_debuglevel(1)
    server.starttls()
    #server.ehlo()

    server.login(username,password)
    server.sendmail(fromaddr,toaddr,msg)
    server.quit()
    return render_template("success.html")