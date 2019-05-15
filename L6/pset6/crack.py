#!/usr/bin/env python3
from  crypt import crypt
from sys import argv


def crack():
    #check input
    if not len(argv)==2:
        print("Usage: python crack.py hash")
        return 1
    #crack
    salt=argv[1][:2]
    alphSet=['']+[chr( ord('a') +i ) for i in range(26)]+[chr( ord('A') +i ) for i in range(26)]
    
    for c1 in alphSet:
        for c2 in alphSet:
            for c3 in alphSet:
                for c4 in alphSet:
                    word=c1+c2+c3+c4 
                    print(f"checking for {word}...")
                    if crypt(word,salt)==argv[1]:
                        print(word)
                        return 0
                     #debug
                    print(f"not {word}, go on checking...")
    print("not found")
    
crack()
