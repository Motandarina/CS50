#include<stdio.h>
#include <stdlib.h>
#include<math.h>
int main(int argc, char *argv[])
{

    float f=atof(argv[1]);
    float width=atof(argv[2]);
    float appValue=1.0/2;
    float minViration=fabs(f-1.0/2);
    float so;
    float mo;
    for(float mom=2.0;mom<=width;mom++)
    {
        for(float son=1.0;son<mom;son++)
        {
            printf("%f/%f: %f\n",son,mom,son/mom);
            if(fabs(f-son/mom)<minViration)
            {
                minViration=fabs(f-son/mom);
                appValue=son/mom;
                so=son;
                mo=mom;
            }
        }
    }
    printf("the nearest value of %f is: %f,which is %f/%f\n",f,appValue,so,mo);

}
