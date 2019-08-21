#include <stdio.h>
typedef struct
{
    char name[20];
    int age;
} Person;
void readData(Person *p);
Person findMiddleAge(Person *p);

int main()
{
    Person man[3], middle;

    readData(man);
    middle = findMiddleAge(man);
    printf("findMiddleAge(): %s %d\n", middle.name, middle.age);
    return 0;
}

void readData(Person *p)
{
    for (int i=0;i<3;i++)
    {
        printf("Enter person %d: \n", i+1);
        scanf("%s %d", &p[i].name, &p[i].age);
    }
}

Person findMiddleAge(Person *p)
{
    int minindex=0, maxindex=0;

    for (int i=1;i<3;i++)
    {
        if (p[i].age<p[minindex].age)
        {
            minindex = i;
        }
        if (p[i].age>p[maxindex].age)
        {
            maxindex = i;
        }
    }

    for (int i=0;i<3;i++)
    {
        if (i!=minindex&&i!=maxindex)
            return p[i];
    }
}
