from nltk.tokenize import sent_tokenize

def compare(list1,list2):
    """compare two lists,return the same items"""
    res=[]
    for line in list1:
        if line in list2 and line not in res:
            res.append(line)
    return res

def lines(a, b):
    """Return lines in both a and b"""
    #file1=open(a,'r')
    #file2=open(b,'r')
    #str1=file1.read();
    #str2=file2.read();
    list1=[]
    list2=[]
    list1=a.splitlines()
    list2=b.splitlines()
    #file1.close()
   # file2.close()
    return compare(list1,list2)


def sentences(a, b):
    """Return sentences in both a and b"""
    list1=[]
    list2=[]
    list1=sent_tokenize(a)
    list2=sent_tokenize(b)
   # print("hi1"+list1[0])
    #print("hi2"+list2[0])
    return compare(list1,list2)

def subs(a,n):
    """Return the n-length substrings of a string"""
    list=[]
    for i in range(len(a)-n+1):
        if a[i:i+n] not in list:
            list.append(a[i:i+n])
    return list

def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    list1=subs(a,n)
    list2=subs(b,n)
    #for i in list1:
    #    print(i)
    #for j in list2:
    #    print(j)
    return compare(list1,list2)