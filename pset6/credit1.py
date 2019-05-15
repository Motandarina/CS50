#!/usr/bin/env python3

#promote for a credit card number
#Number: 
def promote():
    while True:
        input_num=input("Number: ")
        if input_num.isdigit():
            return input_num
#check whether it is valid
    #check fomat
def sumDigit(temp):
    temp=temp*2
    if temp>=10:
        temp=temp%10+temp//10
    return temp


def validate():
    sum=0
    length=len(input_num)
    #debug
    #print(f"length:{length}")
    if length%2==0:
        for i in range(0,length):
            temp=int(input_num[i])
            if i%2==0:
                temp=sumDigit(temp)
            sum+=temp

    else:
        for i in range(0,length):
            temp=int(input_num[i])
            if not i%2==0:
                temp=sumDigit(temp)
            sum+=temp
    #debug
    #print("sum: "+str(sum))
    return sum%10==0
#debug
#print(validate())
#check which kind it belongs
    #start with
    #length
def classify():
    length=len(input_num)
    if length==15 and (input_num[:2]=='34' or input_num[:2]=='37'):
        print("AMEX")
    elif length==16 and ( ( int(input_num[:2]) in range(51,56)) or input_num[:2]=='22'):
        print("MASTERCARD")
    elif (length==13 or length==16) and input_num[0]=='4':
        print("VISA")
    else:
        print("INVALID")

#return result
while True:
    input_num=promote()
    if validate():
        classify()
    else:
        print("INVALID")


