#include <stdio.h>
int reverseDigits1(int num);
void reverseDigits2(int num, int *result);

int main()
{
    int num, result=999;

    printf("Enter a number: \n");
    scanf("%d", &num);
    printf("reverseDigits1(): %d\n", reverseDigits1(num));
    reverseDigits2(num, &result);
    printf("reverseDigits2(): %d\n", result);
    return 0;
}

int reverseDigits1(int num)
{
    int reversed = 0;

    while (num != 0)
    {
        reversed = reversed*10 + num%10;
        num /= 10;
    }
    return reversed;
}

void reverseDigits2(int num, int *result)
{
//    *result = reverseDigits1(num);
    int reversed = 0;

    while (num != 0)
    {
        reversed = reversed*10 + num%10;
        num /= 10;
    }
    *result = reversed;
}

