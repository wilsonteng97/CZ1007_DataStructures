#include <stdio.h>
#define SIZE 10
void transpose2D(int ar[][SIZE], int rowSize, int colSize);
void display(int ar[][SIZE], int rowSize, int colSize);
int main()
{
    int ar[SIZE][SIZE], rowSize, colSize;
    int i,j;

    printf("Enter row size of the 2D array: \n");
    scanf("%d", &rowSize);
    printf("Enter column size of the 2D array: \n");
    scanf("%d", &colSize);
    printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
    for (i=0; i<rowSize; i++)
        for (j=0; j<colSize; j++)
            scanf("%d", &ar[i][j]);
    printf("transpose2D(): \n");
    transpose2D(ar, rowSize, colSize);
    display(ar, rowSize, colSize);
    return 0;
}
void display(int ar[][SIZE], int rowSize, int colSize)
{
    int l,m;
    for (l = 0; l < rowSize; l++)
    {
        for (m = 0; m < colSize; m++)
            printf("%d ", ar[l][m]);
        printf("\n");
    }
}
void transpose2D(int ar[][SIZE], int rowSize, int colSize)
{
    /* Write your program code here */
    int i = 0, j = 0;
    int transposeArr[rowSize][colSize];

    for (i=0; i < rowSize; i++)
    {
        for (j=0; j < colSize; j++)
        {
            transposeArr[j][i] = ar[i][j];
        }
    }

    for (i=0; i < rowSize; i++)
    {
        for (j=0; j < colSize; j++)
        {
            ar[i][j] = transposeArr[i][j];
        }
    }
}
