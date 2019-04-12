#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{

    //recieve parameters and set conditions
    if( argc != 2 )
    {
        fprintf(stderr,"Usage: ./recover image\n");
        return 1;
    }
    //open the file
    FILE * inptf=fopen(argv[1],"r");
    if(inptf==NULL)
    {
        fprintf(stderr,"Could not open %s.\n",argv[1]);
        return 2;
    }

    //repeatedly read the file until the end of the file
    unsigned char ptr[512];
    int num;
    int count=0;
    FILE * img=NULL;
    //debug
    //printf("img address:%p\n",img);

    //debug
    //printf("count address:%p\n",&count);

    while( ( num=fread(ptr, 1, 512, inptf) ) == 512 )
    {
        //set the flag whether we have already opened a jpg file
        char filename[3];
        //for each 512 block find the feature
        if(ptr[0]==0xff && ptr[1]==0xd8 && ptr[2]==0xff && ((ptr[3] & 0xf0) == 0xe0)) //& is bit and operation

            //yes
            {
                //debug
                //printf("branch1\n");

                count++;
                //if already opened a jpg,close it
                if(count>1) fclose(img);
                // prepare a new jpg file name
                //open a new jpg file and write
                //debug
                //printf("branch11\n");
               // printf("count:%03i\n",count-1);
                //printf("count:%d\n",count);
                sprintf(filename,"%03i.jpg",count-1);
                 //debug
                //printf("branch12\n");
                img=fopen(filename,"w");
                //debug
                printf("img address:%p\n",img);
                //debug
                //printf("branch13\n");
                if(img==NULL)
                {
                    fprintf(stderr,"Could not open %s\n",filename);
                    return 2;
                }
                fwrite(ptr,1, 512,img);

            }
        else
            //no
            {
                //already opened a jpg?
                if(count>0)
                    //yes,write
                    fwrite(ptr,1, 512,img);
                    //no,discard and foword
                //debug
                //printf("branch2\n");
            }
    }
    //close file
        //debug
    //printf("end\n");
    fclose(inptf);
    fclose(img);



}