#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct
{
    char name[40];
    char telno[40];
    int id;
    double salary;
} Employee;
int readin(Employee *p);
void printEmp(Employee *p, int size) ;
int search(Employee *p, int size, char *target);
int addEmployee(Employee *p, int size, char *target);
int main()
{
    Employee emp[MAX];
    char name[40];
    int k, size, found=0, ans, choice, result;

    printf("Select one of the following options: \n");
    printf("1: readin()\n");
    printf("2: search()\n");
    printf("3: addEmployee()\n");
    printf("4: print()\n");
    printf("5: exit()\n");
    do
    {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            size = readin(emp);
            break;
        case 2:
            printf("Enter search name: \n");
            scanf("\n");
            gets(name);
            result = search(emp,size,name);
            if (result != 1)
                printf ("Name not found!\n");
            break;
        case 3:
            printf("Enter new name: \n");
            scanf("\n");
            gets(name);
            result = search(emp,size,name);
            if (result != 1)
                size = addEmployee(emp, size, name);
            else
                printf("The new name has already existed in the database\n");
            break;
        case 4:
            printEmp(emp, size);
            break;
        default:
            break;
        }
    }
    while (choice < 5);
    return 0;
}
int readin(Employee *p)
{
    /* write your code here */
    int i = 0;
    char name[40];

    while (1)
    {
        getchar();
        printf("Enter name:\n");
        gets(name);

        if (name[0] == '#')
            break;
        else
            strcpy(p[i].name, name);

        printf("Enter tel:\n");
        gets(p[i].telno);
        printf("Enter id:\n");
        scanf(" %d", &p[i].id);
        printf("Enter salary:\n");
        scanf(" %lf", &p[i].salary);
        i++;
    }

    return i;
}
void printEmp(Employee *p, int size)
{
    /* write your code here */
    printf("The current employee list:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%s %s %d %.2lf\n", p[i].name, p[i].telno, p[i].id, p[i].salary);
    }
}
int search(Employee *p, int size, char *target)
{
    /* write your code here */
    for (int i = 0; i < size; i++)
    {
        if (strcmp(p[i].name, target) == 0)
        {
            printf("Employee found at index location: %d\n", i);
            printf("%s %s %d %.2lf\n", p[i].name, p[i].telno, p[i].id, p[i].salary);
            return 1;
        }
    }

    return 0;
}
int addEmployee(Employee *p, int size, char *target)
{
    /* write your code here */
    if (size == MAX)
        printf("Database is full");
    else
    {
        strcpy(p[size].name, target);
        printf("Enter tel:\n");
        gets(p[size].telno);
        printf("Enter id:\n");
        scanf(" %d", &p[size].id);
        printf("Enter salary:\n");
        scanf(" %lf", &p[size].salary);
        printf("Added at position: %d\n", size++);

        return size;
    }
}
