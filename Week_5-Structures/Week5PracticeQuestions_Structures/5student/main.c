#include <stdio.h>
#include <string.h>
#define SIZE 50
typedef struct
{
    int id;
    char name[50];
} Student;
void inputStud(Student *s, int size);
void printStud(Student *s, int size);
int removeStud(Student *s, int *size, char *target);

int main()
{
    Student s[SIZE];
    int size=0, choice;
    char target[80];
    int result;

    printf("Select one of the following options: \n");
    printf("1: inputStud()\n");
    printf("2: removeStud()\n");
    printf("3: printStud()\n");
    printf("4: exit()\n");
    do
    {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter size: \n");
            scanf("%d", &size);
            printf("Enter %d students: \n", size);
            inputStud(s, size);
            break;
        case 2:
            printf("Enter name to be removed: \n");
            scanf("\n");
            gets(target);
            printf("removeStud(): ");
            result = removeStud(s, &size, target);
            if (result == 0)
                printf("Successfully removed\n");
            else if (result == 1)
                printf("Array is empty\n");
            else if (result == 2)
                printf("The target does not exist\n");
            else
                printf("An error has occurred\n");
            break;
        case 3:
            printStud(s, size);
            break;
        }
    }
    while (choice < 4);
    return 0;
}

void inputStud(Student *s, int size)
{
    int i=0;
    char dummychar;

    while (i<size)
    {
        printf("Student ID: \n");
        scanf("%d", &s[i].id);
        printf("Student Name: \n");
//        scanf("%c", &dummychar);
        scanf("%s", &s[i].name);
//        scanf("%c", &dummychar);
        i++;
    }
}

void printStud(Student *s, int size)
{
    int i=0;

    printf("The current student list: \n");
    while (i<size)
    {
        printf("Student ID: %d Student Name: %s \n", s[i].id, s[i].name);
        i++;
    }
}

int removeStud(Student *s, int *size, char *target)
{
    int i=0;

    if ((*size)==0)
    {
        return 1;
    }
    else
    {
        while (i<*size)
        {
            if (strcmp(s[i].name, target)==0)
            {
                for (int j=i;j<*size;j++)
                {
                    s[j] = s[j+1];
                }
                (*size)--;
                return 0;
            }
            i++;
        }
        return 2;
    }
}
