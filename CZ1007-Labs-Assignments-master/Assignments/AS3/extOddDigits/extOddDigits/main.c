//
//  main.c
//  extOddDigits
//
//  Created by Prem Adithya on 3/9/18.
//  Copyright © 2018 Prem Adithya. All rights reserved.
//

#include <stdio.h>
#define INIT_VALUE 0
int extOddDigits1(int num);
void extOddDigits2(int num, int *result);
int main()
{
    int number, result = INIT_VALUE;
    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("extOddDigits1(): %d\n", extOddDigits1(number));
    extOddDigits2(number, &result);
    printf("extOddDigits2(): %d\n", result);
    return 0;
}
int extOddDigits1(int num)
{
    int newNum = 0, digit, multiplicationFactor = 1;
    
    while (num != 0)
    {
        digit =  num % 10;
        
        if (digit % 2 == 1) {
            newNum += (digit * multiplicationFactor);
            multiplicationFactor *= 10;
        }
        
        num /= 10;
    }
    
    if (newNum == 0)
        return -1;
    else
        return newNum;
}
void extOddDigits2(int num, int *result)
{
    *result = extOddDigits1(num);
}
