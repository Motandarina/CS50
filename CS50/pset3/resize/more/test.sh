#/bin/bash
for i in  {1,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,1.0,2,4,6,8,100}
    {
        echo "for $i"
        /home/ubuntu/workspace/pset3/resize/more/resize $i larg5.bmp student.bmp
        ~cs50/hacker3/resize $i larg5.bmp staff.bmp
        ~cs50/hacker3/peek student.bmp staff.bmp


    }

for i in {0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9}
{
        echo "for $i"
        /home/ubuntu/workspace/pset3/resize/more/resize $i larg5.bmp student.bmp
        ~cs50/hacker3/resize $i larg5.bmp staff.bmp
        ~cs50/hacker3/peek student.bmp staff.bmp

}