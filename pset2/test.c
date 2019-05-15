#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

void main()
{
	char a[]="cba";
	/*
	int c=atoi(a);
	printf("%d",c);
	int b=(int)'1';
	printf("%d",b);
	if (!isalpha(80))
	{
		//printf("%d",isalpha('a'));
		printf("hello");
	}
	*/
	//printf("%d",5*('C'-'A'));
/*	
	for (int i=0,j=0;i<5,j<5;i++)
	{
		printf("hello:%d\n",i+j);
		j++;
	}
*/

	 char str[7]="abcdefg";
	 printf("%s\n",str);           //方式一：数组分配空间不够，导致没地方存放‘\0’,输出乱码
 	 int i;
	 char str1[100];
	 for(i=0;i<7;i++)
	 {
	       str1[i]=str[i];
         }
         printf("%s\n",str1);          //方式二：数组copy过程中，没有copy到'\0'，导致输出
	 char str2[]="hjisajnaiji\0huisajhisaji";    //方式三，printf()和puts()的比较
	 printf("%s\n",str2);
	 puts(str2);


	}
