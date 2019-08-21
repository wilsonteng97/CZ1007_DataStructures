#include <stdio.h>
void specialNumbers1D(int ar[], int num, int *size);

int main()
{
    int a[20],i,size=0,num;

    printf("Enter a number (between 100 and 999): \n");
    scanf("%d", &num);
    specialNumbers1D(a, num, &size);
    printf("specialNumbers1D(): ");
    for (i=0; i<size; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nSize of array: %d \n", size);
    return 0;
}
void specialNumbers1D(int ar[], int num, int *size)
{
    int i = 100;
    int a, b, c;
    double sum = 0;
    for (;i<=num;i++)
    {
        a = (i/10) / 10;
        b = (i/10) % 10;
        c = i % 10;
//        printf("a,b,c = %d, %d, %d\n", a, b, c);
        sum = a*a*a + b*b*b + c*c*c;
        if (i==sum)
        {
//            printf("%d \n", i);
            ar[*size] = i;
            ++(*size);
        }
    }
}
