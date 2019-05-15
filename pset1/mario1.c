#include<stdio.h>

void main(int h)
{
	int i=0;
	do
	{
		h=0;
		printf("Height:");
		i=scanf("%d",&h);
		char c;
		while((c = getchar()) != '\n' && c != EOF);	
		//printf("h:%d\n",h);
	}
	while( i==0 || h<=0 || h>23);
//	printf("%d",h);
	
	
	if(h>0 && h<24)
	{
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<h+3+i;j++)
			{
				if(j<h-i-1)
				{
					printf(" ");
				}
				else if(j>=h-i-1 && j<h)
				{
					printf("#");
				}	
				else if(j>=h+2)
				{
					printf("#");
				}
				else
				{
					printf("  ");
				}
			}
			printf("\n");
		}
	}
	else
		printf("\n");
	
}



