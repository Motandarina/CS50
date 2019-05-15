#!/usr/bin/env python3

from sys import argv

def check():
    #print(argv[1]) 
    if not len(argv)==2:
        print("Usage: python vigenere.py k")
        return False
    elif not argv[1].isalpha():
        print("Usage: python vigenere.py k;k should be character")
        return False
    return True

def promote():
    plaintext=input("plaintext: ")
    return plaintext
    
def shift(c,n):
    n=n.lower()
    s=ord(n)-ord('a')
    if c.islower():
        c=chr( ord('a') + ( (ord(c) - ord('a') ) + s ) % 26 )
    else:
        c=chr( ord('A') + ( (ord(c) - ord('A') ) + s ) % 26 )
    return c

def cipher():
    key=argv[1]
    plaintext=promote()
    print("ciphertexti: ",end='')
    j=0
    for c in plaintext:
        if c.isalpha():
            n=key[ j%(len(key)) ]
            c=shift(c,n)
            j+=1
        print(c,end='')
    print()


if check():
    cipher()
