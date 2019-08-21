#include <stdio.h>
int rCountZeros1(int num);
void rCountZeros2(int num, int *result);

int main()
{
    int number, result=0;

    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("rCountZeros1(): %d \n", rCountZeros1(number));
    rCountZeros2(number, &result);
    printf("rCountZeros2(): %d \n", result);
    return 0;
}

int rCountZeros1(int num)
{
    if (num==0)
    {
        return 0;
    }
    else
    {
        if (num%10==0)
        {
            return rCountZeros1(num/10) + 1;
        }
        return rCountZeros1(num/10);
    }
}

void rCountZeros2(int num, int *result)
{
//    *result = rCountZeros1(num);
    // if (*result>30000)
    // {
    //     *result = 0;
    // }
    if (num==0)
    {
        return;
    }
    else
    {
        if (num%10==0)
        {
            *result += 1;
        }
        rCountZeros2(num/10, result);
    }
}

