#include <stdio.h>
int gcd1(int num1, int num2);
void gcd2(int num1, int num2, int *result);
int main()
{
    int x,y,result=-1;
    printf("Enter 2 numbers: \n");
    scanf("%d %d", &x, &y);
    printf("gcd1(): %d\n", gcd1(x, y));
    gcd2(x,y,&result);
    printf("gcd2(): %d\n", result);
    return 0;
}
int gcd1(int num1, int num2)
{
    /* Write your program code here */
    int temp;

    if (num1 > num2)
    {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    if (num2 % num1 == 0)
        return num1;
    else if (num1 % 2 == 0 && num2 % 2 == 0)
        return num1 / 2;
    else
        return 1;
}
void gcd2(int num1, int num2, int *result)
{
    /* Write your program code here */
    int temp;

    if (num1 > num2)
    {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    if (num2 % num1 == 0)
        *result = num1;
    else if (num1 % 2 == 0 && num2 % 2 == 0
             )
        *result = num1 / 2;
    else
        *result = 1;
}
