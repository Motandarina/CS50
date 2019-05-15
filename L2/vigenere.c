#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int isstrabc(char s[]);

int main(int argc, char* argv[])
{
//step1 check: argc ==2; argv[] alaphbeta; return 1
	
	if (argc!=2 || !isstrabc(argv[1]))
	{
		printf("Usage: ./vigenere k\n");
		return 1;
	}
//step2  readin string
	char str[100];
	printf("plaintext: ");
	//char * str=malloc(100);
	//char* p=NULL;
	//debug
	//printf("hello");
        char *p=fgets(str, 100, stdin);
	if(p==NULL)
	{
		printf("error");
		return 1;
	}
//step3 operate and print
//1.only alaphabetacial letters are encrapted

	
	int len=strlen(str);
	int klen=strlen(argv[1]);
	for (int i=0,j=0;str[i]!='\0';i++)
	{
		if(isalpha(str[i]))
		{
			if(isupper(str[i]))
			{
				str[i]=(str[i]+toupper(argv[1][j])-2*'A')%26+'A';
			}	
			else
			{
				str[i]=(str[i]+tolower(argv[1][j])-2*'a')%26+'a';
			}
			j=(j+1)%klen;
		}
	}
	printf("ciphertext: %s",str);
	return 0;
}


int isstrabc(char s[])
{
	for (int i=0;i<strlen(s);i++)
	{
		if (!isalpha(s[i]))
		{
			return 0;
		}
	
	}
	return 1;
}
