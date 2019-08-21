#include <stdio.h>
#include <math.h>
void specialNumbers1D(int ar[], int number, int *size);
int main()
{
    int a[20],i,size=0,num;

    printf("Enter a number (between 100 and 999): \n");
    scanf("%d", &num);
    specialNumbers1D(a, num, &size);
    printf("specialNumbers1D(): ");
    for (i=0; i<size; i++)
        printf("%d ",a[i]);
    return 0;
}
void specialNumbers1D(int ar[], int number, int *size)
{
    /* Write your code here */
    int i = 100, sum;
    *size = 0;

    while (i <= number)
    {
        sum = pow(i%10, 3) + pow((i/10)%10, 3) + pow(i/100, 3);
        if (sum == i)
        {
            ar[*size] = i;
            (*size)++;
        }

        i++;
    }
}
