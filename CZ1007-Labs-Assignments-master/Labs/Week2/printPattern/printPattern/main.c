//
//  main.c
//  printPattern
//
//  Created by Prem Adithya on 23/8/18.
//  Copyright © 2018 Prem Adithya. All rights reserved.
//

#include <stdio.h>
int main()
{
    int row, col, height;
    int num = 0;
    printf("Enter the height: \n");
    scanf("%d", &height);
    printf("Pattern: \n");
    for (row=1; row <= height; row++)
    {
        col = row;
        num++;
        
        if (num > 3)
            num = 1;
        
        while (col != 0)
        {
            printf("%d", num);
            col--;
        }
        
        printf("\n");
    }
    return 0; }
