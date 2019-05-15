#!/usr/bin/env python3

file=open("banned.txt","r")
a=set()
for line in file:
    a.add(line)
print(a)
