#include<stdio.h>
#include<string.h>

int main()
{
	char str[100];
	printf("Enter a string: ");
	fgets(str, 100, stdin);
	printf("This is your string: %s\n", str);


}
