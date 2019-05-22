#!/usr/bin/env python3

while True:
    change=input("Change owed:")
    try:
        change=float(change)
        if change>0:
            break
    except:
        continue
change=int(change*100)
count=0
count+=change//25
change=change%25
count+=change//10
change=change%10
count+=change//5
change=change%5
count+=change
print(count)

