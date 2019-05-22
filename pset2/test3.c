#include<stdio.h>
#include<string.h>
//test string end code
int main(void)
{
	char *p="abcdef";
	char a[5]="abcde";
	char b[5]="abcde";
	char c[6]={'\0','a','b','c','d','e'};
	
	printf("size of p:%d\n",sizeof(p));
	printf("length of p:%d\n",strlen(p));
	printf("size of abcd:%d\n",sizeof("abcd"));
	printf("length of abcd:%d\n",strlen("abcd"));
	printf("size of a:%d\n",sizeof(a));
	printf("length of a:%d\n",strlen(a));
	printf("size of b:%d\n",sizeof(b));
	printf("length of b:%d\n",strlen(b));
	printf("size of c:%d\n",sizeof(c));
	printf("length of c:%d\n",strlen(c));
	printf("p:%s\n",p);
	printf("p address:%p\n",p);
	printf("a address:%p\n",a);
	
	printf("####0################\n");
	printf("a:%s\n",a);
	//printf("\n");
	for (int i=0;p[i]!='\0';i++)
	{
		printf("p:%c",p[i]);
		printf("\n");
	}
	for (int i=0;i<8;i++)
	{
		printf("p:%c",p[i]);
		printf("\n");
	}
	printf("####1################\n");
	for (int i=0;i<8;i++)
	{
		printf("b:%c",b[i]);
		printf("\n");
	}
	
	printf("####2################\n");
	printf("b:%s\n",b);
	printf("####3################\n");
	printf("c:%s\n",c);
	printf("####4################\n");
	
	for (int i=0;i<10;i++)
	{
		printf("c:%c",c[i]);
		printf("\n");
	}


}
