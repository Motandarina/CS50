#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	
	//read in plaintext
	//operate
	//print result
  	int key;	
	if (argc!=2 || (key=atoi(argv[1]))==0)
	{
		printf("Usage: ./caesar k\n");
		return 1;
	}
	printf("plaintext: ");
//	printf("%d",key);
	
	key=key%26;
	char p[100];
	fgets(p,100,stdin);
//scanf("%s",p);
	//int i=0,r=0;
// 	printf("%s\n",p);	

	for(int i=0,l=strlen(p);i<l;i++)
	{
	//	printf("hello1\n");
		if(islower(p[i]))
		{
		//	p[i]=(p[i]+key)%26;
			p[i]=(p[i]+key-97)%26+97;
		}
		if(isupper(p[i]))
		{
			//p[i]=p[i]+key;
			p[i]=(p[i]+key-65)%26+65;	
		
		}
		
	
	}
	printf("ciphertext: %s\n",p);
	
	
	return 0;



}
