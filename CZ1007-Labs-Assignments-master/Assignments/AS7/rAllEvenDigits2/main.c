#include <stdio.h>
#define INIT_VALUE -1
void rAllEvenDigits2(int num, int *result);
int main()
{
    int number, result=INIT_VALUE;
    printf("Enter a number: \n");
    scanf("%d", &number);
    rAllEvenDigits2(number, &result);
    if (result == 1)
        printf("rAllEvenDigits2(): yes\n");
    else if (result == 0)
        printf("rAllEvenDigits2(): no\n");
    else
        printf("rAllevenDigits2(): error\n");
    return 0;
}
void rAllEvenDigits2(int num, int *result)
{
    /* Write your code here */
    int digit;

    if (num < 10)
    {
        digit = num;

        if (digit % 2 == 0)
            *result = 1;
        else
            *result = 0;
    }
    else
    {
        digit = num % 10;

        if (digit % 2 == 0)
        {
            *result = 1;
            rAllEvenDigits2(num/10, result);
        }
        else
            *result = 0;
    }
}
