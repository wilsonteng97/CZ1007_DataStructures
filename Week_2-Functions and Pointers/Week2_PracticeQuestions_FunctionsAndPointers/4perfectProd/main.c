#include <stdio.h>
int perfectProd1(int num);
void perfectProd2(int num, int *prod);

int main()
{
    int number, result=0;

     printf("Enter a number: \n");
     scanf("%d", &number);
     printf("perfectProd1(): %d\n", perfectProd1(number));
     perfectProd2(number, &result);
     printf("perfectProd2(): %d\n", result);
     return 0;
}

int perfectProd1(int num)
{
    int n, i, sum;
    int result;

    if (num>=6)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    for (n=1;n<=num;n++)
    {
        i = 1;
        sum = 0;

        while (i<n)
        {
            if (n%i==0)
            {
                sum += i;
            }
            i++;
        }
        if (sum==n)
        {
            printf("%d is a perfect number\n", n);
            result *= n;
        }
    }
    return result;
}

void perfectProd2(int num, int *prod)
{
//    *prod = perfectProd1(num);
    int n, i, sum;
    *prod = 1;

    if (num>=6)
    {
        *prod = 1;
    }
    else
    {
        *prod = 0;
    }

    for (n=1;n<=num;n++)
    {
        i = 1;
        sum = 0;

        while (i<n)
        {
            if (n%i==0)
            {
                sum += i;
            }
            i++;
        }
        if (sum==n)
        {
            *prod *= n;
        }
    }
}
