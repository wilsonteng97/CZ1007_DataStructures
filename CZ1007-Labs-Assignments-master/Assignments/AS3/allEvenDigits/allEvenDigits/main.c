//
//  main.c
//  allEvenDigits
//
//  Created by Prem Adithya on 3/9/18.
//  Copyright © 2018 Prem Adithya. All rights reserved.
//

#include <stdio.h>
#define INIT_VALUE -1
int allEvenDigits1(int num);
void allEvenDigits2(int num, int *result);
int main()
{
    int number, result = INIT_VALUE;
    printf("Enter a number: \n");
    scanf("%d", &number);

    printf("allEvenDigits1(): ");
    result = allEvenDigits1(number);
    if (result == 1)
        printf("All Even\n");
    else if (result == 0)
        printf("Not All Even\n");
    else
        printf("Error\n");
    allEvenDigits2(number, &result);
    printf("allEvenDigits2(): ");
    if (result == 1)
        printf("All Even\n");
    else if (result == 0)
        printf("Not All Even\n");
    else
        printf("Error\n");
    return 0;
}
int allEvenDigits1(int num)
{
    while (num > 0) {
        if (num % 10 % 2 == 0)
        {
            num /= 10;
        }
        else
            return 0;
    }
    
    return 1;
}
void allEvenDigits2(int num, int *result)
{
    *result = allEvenDigits1(num);
}
