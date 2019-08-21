#include <stdio.h>
int rAllOddDigits1(int num);
void rAllOddDigits2(int num, int *result);

int main()
{
    int number, result=-1;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("rAllOddDigits1(): %d\n", rAllOddDigits1(number));
    rAllOddDigits2(number, &result);
    printf("rAllOddDigits2(): %d\n", result);
    return 0;
}

int rAllOddDigits1(int num)
{
    if (num!=0)
    {
        if ((num%10)%2==0)
            return 0;
        else
            return rAllOddDigits1(num/10);
    }
    else
        return 1;
}

void rAllOddDigits2(int num, int *result)
{
    if (num!=0)
    {
        if ((num%10)%2==0)
        {
            *result = 0;
            return;
        }
        else
            rAllOddDigits2(num/10, result);
    }
    else
        *result = 1;
}
