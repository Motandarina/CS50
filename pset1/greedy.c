#include<stdio.h>

//25,10,5,1


int greedy(int x);
void main(void)
{
	float m=0;
	printf("O hai! ");
	do
	{
		printf("How much change is owed?\n");
		scanf("%f",&m);
		char c;
		while((c = getchar()) != '\n' && c!=EOF);
	}while(m<=0);
	
	//debug print input number
	//printf("%f\n",m);
	float x=100*m;
	//debug print 10*m
	//printf("%f\n",x);
	//printf("%d\n",(int)x);
	int c=greedy((int)x);
	printf("%d\n",c);

}

int greedy(int x)
{
	int count=0;
	if(x>=25)
	{
		x=x-25;
		count++;
		count+=greedy(x);
	}
	else if(x>=10)
	{
		x=x-10;
		count++;
		count+=greedy(x);
	}
	else if(x>=5)
	{
		x=x-5;
		count++;
		count+=greedy(x);
	}
	else
	{
		count=count+x;
	}
	return count;

}

