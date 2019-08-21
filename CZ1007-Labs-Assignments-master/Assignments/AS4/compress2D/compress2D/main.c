//
//  main.c
//  compress2D
//
//  Created by Prem Adithya on 12/9/18.
//  Copyright © 2018 Prem Adithya. All rights reserved.
//

#include <stdio.h>
#define SIZE 100
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize);
int main()
{
    int data[SIZE][SIZE];
    int i,j;
    int rowSize, colSize;
    printf("Enter the array size (rowSize, colSize): \n");
    scanf("%d %d", &rowSize, &colSize);
    printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
    for (i=0; i<rowSize; i++)
        for (j=0; j<colSize; j++)
            scanf("%d", &data[i][j]);
    printf("compress2D(): \n");
    compress2D(data, rowSize, colSize);
    return 0;
}
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize)
{
    /* Write your program code here */
    int currentValue, count;
    
    for (int i=0; i < rowSize; i++)
    {
        currentValue = *(*(data + i) + 0);
        count = 0;
        
        for (int j=0; j < colSize; j++)
        {
            if (*(*(data + i) + j) == currentValue)
                count++;
            else
            {
                printf("%d %d ", currentValue, count);
                count = 1;
                currentValue = *(*(data + i) + j);
            }
        }
        
        printf("%d %d\n", currentValue, count);
    }
}
