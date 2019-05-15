#include<stdio.h>
#define _XOPEN_SOURCE       /* See feature_test_macros(7) */
#include <unistd.h>
#include <string.h>

char *crypt(const char *key, const char *salt);

int main(int argn, char * x[])
{


	//x
	//salt
	//  char *crypt(const char *key, const char *salt);
	
	//salt
	char salt[2];
	strncpy(salt,x[1],2);

/*	
	 for (int i=0;i<2;i++)
	{
		salt[i]=x[1][i];
	}
*/ 
//	printf("%s\n",salt);	
	
	//char set
	//char set[53]={'\0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
	//	'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

	
	char set[53];
	set[0] = '\0';
	for (int i = 'A', count = 1; i <= 'z'; i++)
	{
		if (i > 'Z' && i < 'a') continue;							                
		set[count] = i;
		count++;
	}

	/*
	 * for(int i=0;i<52;i++)
	{
		printf("%c",set[i]);
	}
	*/
/*	
	char se[53];
	
	se[0]='\0';
	for(int i=0;i<53;i++)
	{
		if(i<26)
			se[i+1]='a'+i;
		else
			se[i+1]='A'+i-26;
		printf("%c\n",se[i]);
	}
*/	
	//se[52]='\0';
	
//	printf("%d\n",strcmp(set,se));
	
	
/*	
	if(strcmp(set,se)==0)
		printf("same");
	else
		printf("diff");
*/
	/*
	for(int i=0;i<53;i++)
	{
		printf("%c",se[i]);
	}
	*/
	//printf("%s\n",set);

	//decrypt
	char s[5];
	/*
	for(int i=0;i<52;i++)
	{
		s[0]=set[i];
		s[1]='\0';
		if(crypt(s,salt)==*x)
		{
			printf("%s",s);
		}
	}

	for(int i=0;i<52;i++)
	{
		for(int j=0;j<52;j++)
		{
			s[0]=set[i];
			s[1]=set[j];
			s[2]='\0';
			if (crypt(s,salt)==*x)
			{
				printf("%s",s);
			}
		}
	}
	
	
	for(int i=0;i<52;i++)
	{
		for(int j=0;j<52;j++)
		{
			for(int k=0;k<52;k++)
			{
				s[0]=set[i];
				s[1]=set[j];
				s[2]=set[k];
				s[3]='\0';
				if (crypt(s,salt)==*x)
				{
					printf("%s",s);
				}
			}
		}
	}
	
*/
	for(int i=0;i<53;i++)
	{
		s[0]=set[i];
		for(int j=0;j<53;j++)
		{
			s[1]=set[j];
			for(int k=0;k<53;k++)
			{
				s[2]=set[k];
				for(int l=0;l<53;l++)
				{
					s[3]=set[l];
					s[4]='\0';
		//			printf("%s\n	",s);
					if (strcmp(crypt(s,salt),x[1])==0)
					{
						printf("%s \n",s);
						return 0;
					}
				}
			}
		}
	}
	
	return 1;


}
