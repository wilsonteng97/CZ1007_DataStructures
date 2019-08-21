#include <stdio.h>
void rGcd2(int num1, int num2, int *result);
int main()
{
    int n1, n2, result;
    printf("Enter 2 numbers: \n");
    scanf("%d %d", &n1, &n2);
    rGcd2(n1, n2, &result);
    printf("rGcd2(): %d\n", result);
    return 0;
}
void rGcd2(int num1, int num2, int *result)
{
    /* Write your code here */
    if (*result == 0)
    {
        if (num1 < num2)
            *result = num1;
        else
            *result = num2;
    }

    if ((num1 % *result != 0) || (num2 % *result != 0))
    {
        *result -= 1;
        rGcd2(num1, num2, result);
    }
}
