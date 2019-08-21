//
//  main.c
//  Power
//
//  Created by Prem Adithya on 16/8/18.
//  Copyright © 2018 Prem Adithya. All rights reserved.
//

#include <stdio.h>

int main()
{
    float p,i,r;
    
    printf("Enter the current:  \n");
    scanf("%f", &i);
    printf("Enter the resistance: \n");
    scanf("%f", &r);
    
    p = i * i * r;
    
    printf("The power loss: %.2f\n", p);
    return 0;
}
