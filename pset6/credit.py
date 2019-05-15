#!/usr/bin/env python3

#promote for a credit card number
#Number: 
while True:
    input_num=input("Number: ")
    if input_num.isdigit():
    #    num=long(input_num)
        break
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
    num=int(input_num)
    p12=10**12
    p13=10*p12
    p14=10*p13
    p15=10*p14
    
    am2=num//p13
    mst2=num//p14
    visa1=num//p12 if length==13 else num//p15
    if length==15 and (am2==34 or am2==37):
        print("AMEX")
    elif length==16 and ( (mst2 in range(51,56)) or mst2==22):
        print("MASTERCARD")
    elif (length==13 or length==16) and visa1==4:
        print("VISA")
    else:
        print("INVALID")

#return result

if validate():
    classify()
else:
    print("INVALID")
    

