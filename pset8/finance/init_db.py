from cs50 import SQL
# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

str0="DROP TABLE users"
str1="DROP TABLE purchases"
str2="DROP TABLE history"
str3="CREATE TABLE 'users' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, 'username' TEXT NOT NULL, 'hash' TEXT NOT NULL, 'cash' NUMERIC NOT NULL DEFAULT 10000.00 );"
str4="CREATE UNIQUE INDEX 'username' ON 'users' ('username');"
str5="CREATE TABLE 'purchases'('uid' integer NOT NULL , 'symbol' varchar(10)  NOT NULL,'shares' integer NOT NULL );"

str6="CREATE TABLE 'history'('uid' integer NOT NULL , 'symbol' varchar(10)  NOT NULL,'name' varchar(50)  NOT NULL,'shares' integer NOT NULL,'prices' NUMERIC NOT NULL,'time' datetime not null);"

str7="CREATE INDEX 'uid' ON 'purchases' ('uid');"
str8="CREATE INDEX 'huid' ON 'history' ('uid');"
str9="CREATE INDEX 'symbol' ON 'purchases' ('symbol');"

db.execute(str0)
db.execute(str1)
db.execute(str2)
db.execute(str3)
db.execute(str4)
db.execute(str5)
db.execute(str6)
db.execute(str7)
db.execute(str8)
db.execute(str9)
