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
 	printf("%s\n",p);	

	for(int i=0,l=strlen(p);i<l;i++)
	{
	//	printf("hello1\n");
		if(p[i]>='a' && p[i]<='z')
		{
		//	p[i]=(p[i]+key)%26;
			//printf("hello2\n");
			if((p[i]+key)>'z')
			{
				p[i]=p[i]+(key-'z'+'a'-1);
			}
			else
			{
				p[i]=p[i]+key;
			}
			//printf("B:%c\n",p[i]);
			//printf("A:%c\n",p[i]);
		}
		if(p[i]>='A' && p[i]<='Z')
		{
			//p[i]=p[i]+key;
			
			if(p[i]+key>'Z')
			{
				p[i]=p[i]+(key-'Z'+'A'-1);
			}
			else
			{
				p[i]=p[i]+key;
			}
		
		}
		
	
	}
	printf("ciphertext: %s\n",p);
	
	
	return 0;



}
