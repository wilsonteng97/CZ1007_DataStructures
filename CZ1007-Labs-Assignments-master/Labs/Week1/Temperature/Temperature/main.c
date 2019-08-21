//
//  main.c
//  Temperature
//
//  Created by Prem Adithya on 16/8/18.
//  Copyright © 2018 Prem Adithya. All rights reserved.
//

#include <stdio.h>

int main()
{
    float fahrenheit, celsius; // declare variables
    
    printf("Enter the temperature in degree F: \n");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit-32)*(5.0/9.0);
    printf("Converted degree in C: %.2f\n", celsius);
    return 0;
}
