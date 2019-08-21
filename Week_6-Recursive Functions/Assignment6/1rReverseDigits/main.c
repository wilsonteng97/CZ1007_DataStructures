#include <stdio.h>
#include <math.h>
void rReverseDigits(int num, int *results);

int main()
{
    int result=0, number;

    printf("Enter a number: \n");
    scanf("%d", &number);
    rReverseDigits(number, &result);
    printf("rReverseDigits(): %d\n", result);
    return 0;
}

void rReverseDigits(int num, int *result)
{
    if (num==0)
    {
        return;
    }
    else
    {
        *result *= 10;
        *result += (num%10);
        rReverseDigits(num/10, result);
    }
}
