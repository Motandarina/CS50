#include<stdio.h>
#include <stdlib.h>
int main(void)
{
    int a=0;
    int *p=NULL;
    p=malloc(sizeof(int));
    *p=5;
    printf("address of p before free:%p\n",p);
    printf("value of p:%d\n",*p);
    //int x=free(p);  void free()
   // printf("x is %d\n",x);
    //*p=6;
    printf("address of p after free:%p\n",p);
    //printf("value of p:%d\n",*p);
    printf("address of pointer is still unchanged after freed\n");
    return 0;


}