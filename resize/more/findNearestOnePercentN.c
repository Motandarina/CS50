#include<stdio.h>
#include <stdlib.h>
#include<math.h>
int main(int argc, char *argv[])
{

    float f=atof(argv[1]);
    float width=atof(argv[2]);
    float appValue=1.0/2;
    float minViration=fabs(f-1.0/2);
    float mo=2.0;
    for(float mom=2.0;mom<=width;mom++)
    {
            printf("1/%f: %f\n",mom,1.0/mom);
            if(fabs(f-1.0/mom)<minViration)
            {
                minViration=fabs(f-1.0/mom);
                appValue=1.0/mom;
                mo=mom;
            }
    }
    printf("the nearest value of %f is: %f,which is 1.0/%f\n",f,appValue,mo);

}
