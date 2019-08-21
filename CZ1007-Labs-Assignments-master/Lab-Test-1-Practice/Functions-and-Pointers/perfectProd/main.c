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
    /* Write your code here */
    int i, j, sum, perfectProd = 1;

    for (i = 1; i < num; i++)
    {
        sum = 0;

        for (j = 1; j < i; j++)
        {
            if (i % j == 0)
                sum += j;
        }

        if (i == sum)
            perfectProd *= i;
    }

    if (perfectProd == 1)
        return 0;
    else
        return perfectProd;
}
void perfectProd2(int num, int *prod)
{
    /* Write your code here */
    int i, j, sum;
    *prod = 1;

    for (i = 1; i < num; i++)
    {
        sum = 0;

        for (j = 1; j < i; j++)
        {
            if (i % j == 0)
                sum += j;
        }

        if (i == sum)
            *prod *= i;
    }

    if (*prod == 1)
        *prod = 0;
}
