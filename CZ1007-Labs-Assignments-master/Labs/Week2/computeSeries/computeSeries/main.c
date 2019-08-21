//
//  main.c
//  computeSeries
//
//  Created by Prem Adithya on 23/8/18.
//  Copyright © 2018 Prem Adithya. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int factorial(int i);

int main()
{
    int n, denominator = 1;
    float x, result = 1.0, numerator = 1.0;
    printf("Enter x: \n");
    scanf("%f", &x);
    
    for (n=1; n <= 10; n++)
    {
        numerator = pow(x, n);
        denominator = factorial(n);
        result += (numerator / denominator);
    }
    
    printf("Result = %.2f\n",  result);
    return 0;
    
}

int factorial(int i)
{
    if (i >= 1)
        return i * factorial(i-1);
    else
        return 1;
}
