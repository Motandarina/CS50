#!/usr/bin/env python3

while True:
    height=input("Height:")
    if height.isdigit():
        height=int(height)
        if height in range(1,9):
            break

for i in range(height):
    for j in range(height):
        if j<height-i-1:
            print(" ",end='')
        else:
            print("#",end='')
    print("  ",end='')
    for j in range(i+1):
        print("#",end='')
    print()
