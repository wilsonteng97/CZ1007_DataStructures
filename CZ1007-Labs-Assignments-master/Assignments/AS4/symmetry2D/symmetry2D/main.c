//
//  main.c
//  symmetry2D
//
//  Created by Prem Adithya on 12/9/18.
//  Copyright © 2018 Prem Adithya. All rights reserved.
//

#include <stdio.h>
#define SIZE 10
#define INIT_VALUE -1
int symmetry2D(int M[][SIZE], int rowSize, int colSize);
int main()
{
    int M[SIZE][SIZE],i,j, result = INIT_VALUE;
    int rowSize, colSize;
    
    printf("Enter the array size (rowSize, colSize): \n");
    scanf("%d %d", &rowSize, &colSize);
    printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
    for (i=0; i<rowSize; i++)
        for (j=0; j<colSize; j++)
            scanf("%d", &M[i][j]);
    result=symmetry2D(M, rowSize, colSize);
    if (result == 1)
        printf("symmetry2D(): Yes\n");
    else if (result == 0)
        printf("symmetry2D(): No\n");
    else
        printf("Error\n");
    return 0;
}
int symmetry2D(int M[][SIZE], int rowSize, int colSize)
{
    /* Write your code here */
    for (int i = 0; i < colSize; i++)
    {
        if (M[0][i] != i+1)
            return 0;
        
        if (M[i][0] != i+1)
            return 0;
    }
    
    return 1;
}
