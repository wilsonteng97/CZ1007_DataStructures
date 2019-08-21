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
    /* Write your program code here */
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("Enter person %d: \n", i+1);
        scanf("%s %d", &p[i].name, &p[i].age);
        //scanf("\n");
    }
}
Person findMiddleAge(Person *p)
{
    /* Write your program code here */
    int min = p[0].age, max = p[0].age, minIndex = 0, maxIndex = 0, i = 0;

    for (i = 0; i < 3; i++)
    {
        if (min > p[i].age)
        {
            min = p[i].age;
            minIndex = i;

        }
        if (max < p[i].age)
        {
            max = p[i].age;
            maxIndex = i;
        }
    }

    for (i = 0; i < 3; i++)
    {
        if (i != minIndex && i != maxIndex)
            return p[i];
    }
}
