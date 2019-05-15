#include<stdio.h>
#include<string.h>
#include<math.h>
/*
 *AMEX American Express :15-digit numbers
 * 	start with 34 or 37
 *MASTERCARD MasterCard: 16-digits numbers
 * 	start with 51,52,53,54,55
 *VISA Visa uses 13- or 16-digit numbers
 *	start with 4
 *INVALID
 *verify a card:
 *1.Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products' digits together.

 Add the sum to the sum of the digits that weren’t multiplied by 2.

 If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

 */
int verifyCard(long long int c);
void classify(long long int c);

int main(void)
{
	long long int d=0;
	int z=0;
	do
	{
		//promote
		printf("Number: ");
		//get input
		z=scanf("%lld",&d);
		//debug: print d
		printf("%lld\n",d);
		char c;
		while((c=getchar())!='\n' && c!=EOF);		
	}while(d==0 || z==0);
	//deal with cache
	//validate
	//debug
	//print d
//	printf("%lld\n",d);
//	classify(d);
	if(verifyCard(d)==1)
	{
		classify(d);
	}
	else
	{
		//debug
		//print
		//printf("h\n");
		printf("INVALID\n");
	}
	//classify
	

return 0;
}

int cald(int d)
{
	int sum=0;
	d=2*d;
	sum=d/10+d%10;
	return sum;

}

int verifyCard(long long int c)
{
	long long int res=c;
	char str[20]="";
	sprintf(str,"%lld",c);
	int len=strlen(str);
	//debug
	//printf("c:%lld\n",c);
	//printf("lens:%d\n",len);
	int digit=0;	
	int sum1=0;
	int sum2=0;
	int sum=0;
	//branch when length is even 2
	if(len%2==0)
	{
		//debug
		//print hello
	//	printf("hello\n");
		for(int i=0;i<len;i++)
		{
			digit=res%10;
			res=res/10;
			if(i%2==0)
			{
				sum1+=cald(digit);
			}
			else
			{
				sum2+=digit;
			}

		}
		sum=sum1+sum2;
	
	}
	//branch when length is odd 1
	else
	{
		for(int i=0;i<len;i++)
		{
			digit=res%10;
			res=res/10;
			//debug
		//	printf("lens:%d\n",len);
			//printf("i:%d\n",i);
			//printf("digit:%d\n",digit);
			if(i%2==0)
			{
				sum1+=digit;
				//debug:print i digit
			//	printf("i:%d\n",i);
			//	printf("digit:%d\n",digit);

			}
			else
			{
				sum2+=cald(digit);
			//	printf("#################\n");
			//	printf("i:%d\n",i);
			//	printf("cald(digit):%d\n",cald(digit));
			}
		}
		sum=sum1+sum2;
		//debug,print sum
		//printf("sum1:%d\n",sum1);
		//printf("sum2:%d\n",sum2);
		//printf("sum:%d\n",sum);
	}
	//debug: print sum
	//printf("sum:%d\n",sum);
	if(sum%10==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	//loop to deal with every other digit
	//get digit by mod
	//mutipliy by 2
	//get digit and add
	//validate if the total modulo 10 is congruent to 0
}

void classify(long long int c)
{
  /*
  *AMEX American Express :15-digit numbers
  *      start with 34 or 37
  *MASTERCARD MasterCard: 16-digits numbers
  *      start with 51,52,53,54,55
  *VISA Visa uses 13- or 16-digit numbers
  *      start with 4
  *INVALID	 
  */
  char str[20]="";
  sprintf(str,"%lld",c);
  int len=strlen(str);
  long long int p13=pow(10,13);
  long long int p14=pow(10,14);
  long long int p12=pow(10,12);
  long long int p15=pow(10,15);
  printf("c/p12\n",c/p12);
  printf("c/p13\n",c/p13);
  printf("c/p14\n",c/p14);
  printf("c/p15\n",c/p15);
  if(len==15 && (c/p13==34 || c/p13==37))
  {
//printf("a:%d",c/pow(10,13));
  	  printf("AMEX\n");	
  }
  else if(len==16 && ((c/p14>=51 && c/p14<=55) || (c/p14==22)))
  {
  	printf("MASTERCARD\n");
	//printf("sss:%d",c/10^14);
  }
  else if((len==13 && c/p12==4) || (len==16 && c/p15==4))
  {
 	printf("VISA\n");
  }
  else
  {
  	printf("INVALID\n");
  }
}
