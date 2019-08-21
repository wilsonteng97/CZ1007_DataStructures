#include <stdio.h>
int countOddDigits1(int num);
void countOddDigits2(int num, int *result);

int main()
{
    int number, result=-1;

     printf("Enter the number: \n");
     scanf("%d", &number);
     printf("countOddDigits1(): %d\n", countOddDigits1(number));
     countOddDigits2(number, &result);
     printf("countOddDigits2(): %d\n", result);
     return 0;
}
int countOddDigits1(int num)
{
    int count = 0;
    while (num > 0)
    {
        if ((num%10)%2 != 0)
        {
            count++;
        }
        num /= 10;
    }
    return count;
}

void countOddDigits2(int num, int *result)
{
//    *result = countOddDigits1(num);
    *result = 0;
    while (num > 0)
    {
        if ((num%10)%2 != 0)
        {
            (*result)++;
        }
        num /= 10;
    }
}
