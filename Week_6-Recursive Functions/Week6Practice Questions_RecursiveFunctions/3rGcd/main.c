#include <stdio.h>
int rGcd1(int num1, int num2);
void rGcd2(int num1, int num2, int *result);

int main()
{
    int n1, n2, result;

    printf("Enter 2 numbers: \n");
    scanf("%d %d", &n1, &n2);
    printf("rGcd1(): %d\n", rGcd1(n1, n2));
    rGcd2(n1, n2, &result);
    printf("rGcd2(): %d\n", result);
    return 0;
}

int rGcd1(int num1, int num2)
{
    if (num2!=0)
        return rGcd1(num2, num1%num2);
    else
        return num1;
}

void rGcd2(int num1, int num2, int *result)
{
    if (num2!=0)
    {
        rGcd2(num2, num1%num2, result);
    }
    else
    {
        *result = num1;
    }
}
