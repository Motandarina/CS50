#!/usr/bin/env python3

from sys import argv

fList=set()
inList=[]

def main():
   #check
    if not check():
        return 1
   #load
    load()
   
   #promote and read input in list2
    readInList() 
   #compare input with list,check if list2 words is in list1
    #debug
    #print(fList)
    #print(inList)
    for w in inList:
        if w.lower() in fList:
            inList[inList.index(w)]=len(w)*'*'
    #yes 
        #caculate the length of word
        #replace the word with length number of *
   #print result
    print(' '.join(inList))
def readInList():
   #promote
    inp=input("What message would you like to censor?\n")   
    for word in inp.split(' '):
        inList.append(word.rstrip("\n"))


def check():
    if not len(argv)==2:
        print("Usage: python bleep.py dictionary")
        return False
    return True

def load():
    #open file read in the lines in list1
    file=open(argv[1],'r')
    for line in file:
        fList.add(line.rstrip('\n'))
    file.close
    return True

if __name__ == "__main__":
    main()
