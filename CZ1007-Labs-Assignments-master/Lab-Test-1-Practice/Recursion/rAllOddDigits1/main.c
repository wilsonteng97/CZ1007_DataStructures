#include <stdio.h>
int rAllOddDigits1(int num);
int main()
{
    int number;
    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("rAllOddDigits1(): %d\n", rAllOddDigits1(number));
    return 0;
}
int rAllOddDigits1(int num)
{
    /* Write your code here */
    if ((num > 0) && (num < 10))
    {
        if (num % 2 == 0)
            return 0;
        else
            return 1;
    }
    else
    {
        if ((num % 10) % 2 == 0)
            return 0;
        else
            return rAllOddDigits1(num/10);
    }
}
