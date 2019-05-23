#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    char *dorm;
}
student;


int cmp(const void *a, const void *b);

int main(void)
{
    //debug1
    //student s={"Stelios", "Branford"};
   // printf("s:%s\n",s.name);

   //debug2:
   //char *s="abcd"
    student heads[] =
    {
        {"Stelios", "Branford"},
        {"Maria", "Cabot"},
        {"Anushree", "Ezra Stiles"},
        {"Brian", "Winthrop"}
    };
    printf("Before:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%s from %s\n", heads[i].name, heads[i].dorm);
    }
    qsort(heads, 4, sizeof(student), cmp);
    printf("After:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%s from %s\n", heads[i].name, heads[i].dorm);
    }
}

int cmp(const void *a, const void *b)
{
    //cast type to *student
    student *namea=(student *)a;
    student *nameb=(student *)b;
    //compare *(student.name)
    //strcmp
    return strcmp(namea->name,nameb->name);
}
