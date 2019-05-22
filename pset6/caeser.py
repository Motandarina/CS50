#!/usr/bin/env python3

from sys import argv

def encap():
    #check for useage
    # Usage: python caesar.py k
   

   # print(len(argv))
   # print(argv[0])
   # print(argv[1])
    if not len(argv)==2:
        print("Usage: python caesar.py k")
        return 1

    if not argv[1].isdigit():
        print("k should be a number")
        return 1

    #promote for input
    #plaintext:  
    plaintext=input("plaintext: ")
    print("ciphertext: ",end='')
    #do ciphering
    k=int(argv[1])
    for c in plaintext:
        if c.isalpha():
            if c.isupper():
                print( chr( ord('A') + ( ord(c) + k%26 - ord('A') ) % 26),end='' )
            else:
                print( chr( ord('a') + ( ord(c) + k%26 - ord('a') ) % 26),end='' )
        else:
            print(c,end='')
    print()
encap()

#print result
#ciphertext: 

