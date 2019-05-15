#!/usr/bin/env python3

while True:
    height=input("Height:")
    if height.isdigit():
        height=int(height)
        if height in range(1,9):
            break

for i in range(height):
    print(" "*(height-i-1),end='')
    print("#"*(i+1),end='')
    print("  ",end='')
    print("#"*(i+1),end='')
    print()
