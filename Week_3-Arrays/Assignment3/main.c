#include <stdio.h>
#define MAX 10
void initialize(int *size, int ar[]);
void insert(int max, int *size, int ar[], int num);
void iremove(int *size, int ar[], int num);
void display(int size, int ar[]);

int main()
{
    int option = 0;
    int num, ar[MAX], size = 0;

    printf("Please select an option: \n");
    printf("(1) Initialize the array \n");
    printf("(2) Insert an integer \n");
    printf("(3) Remove an integer \n");
    printf("(4) Display the numbers stored in the array \n");
    printf("(5) Quit \n");

    do {
        printf("Enter your choice: \n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                initialize(&size, ar);
                break;
            case 2:
                printf("Enter an integer: \n");
                scanf("%d", &num);
                insert(MAX, &size, ar, num);
                break;
            case 3:
                printf("Enter the integer to be removed: \n");
                scanf("%d", &num);
                iremove(&size, ar, num);
                break;
            case 4:
                display(size, ar);
                break;
            default:
                break;
        }
    } while (option < 5);
    return 0;
}

void display(int size, int ar[])
{
    int i;

    printf("The %d numbers in the array: \n", size);
    for(i = 0; i < size; i++)
        printf("%d ", ar[i]);
    printf("\n");

}

void initialize(int *size, int ar[])
{
    int i, num, tempsize;

    *size = 0;
    printf("Enter the total number of integers (MAX=10): \n");
    scanf("%d", &tempsize);
    while ((tempsize>10)||(tempsize<=0))
    {
        printf("Enter the total number of integers (MAX=10): \n");
        scanf("%d", &tempsize);
    }

    printf("Enter the integers: \n");
    for (i=0;i<(tempsize);i++)
    {
        scanf("%d", &num);
        insert(MAX, size, ar, num);
    }
}

void insert(int max, int *size, int ar[], int num)
{
    int newindex, i, j, temp;

    if ((*size)>=max)
        printf("The array is full \n");
    else
    {
//        ar[(*size)++] = num;
        newindex = (*size)++;
        ar[newindex] = num;
    }

    for (i=(*size);i>0;i--)
    {
        for (j=0;j<(i-1);j++)
        {
            if (ar[j]>ar[j+1])
            {
                temp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = temp;
            }
        }
    }
}

void iremove(int *size, int ar[], int num)
{
    int i, appear=0, position, j;

    if ((*size)==0)
    {
        appear = 1;
        printf("The array is empty \n");
    }
    else
    {
        i = 0;
        while (i<(*size))
        {
            if (ar[i]==num)
            {
                appear = 1;
                position = i;
                for (j=position;j<((*size)-1);j++)
                {
                    ar[j] = ar[j+1];
                }
                (*size)--;
                printf("The integer is removed \n");
                break;
            }
            i++;
        }

    }

    if (appear!=1)
    {
        printf("The number is not in the array \n");
    }
}
