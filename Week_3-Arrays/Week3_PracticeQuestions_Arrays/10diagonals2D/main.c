#include <stdio.h>
#define SIZE 10
void diagonals2D(int ar[][SIZE], int rowSize, int colSize, int *sum1, int *sum2);

int main()
{
    int ar[SIZE][SIZE], rowSize, colSize;
    int i, j, sum1=0, sum2=0;

    printf("Enter row size of the 2D array: \n");
    scanf("%d", &rowSize);
    printf("Enter column size of the 2D array: \n");
    scanf("%d", &colSize);
    printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
    for (i=0; i<rowSize; i++)
    {
        for (j=0; j<colSize; j++)
        {
            scanf("%d", &ar[i][j]);
        }
    }
    diagonals2D(ar, rowSize, colSize, &sum1, &sum2);
    printf("sum1=%d; sum2=%d\n",sum1,sum2);
}

void diagonals2D(int ar[][SIZE], int rowSize, int colSize, int *sum1, int *sum2)
{
    int i;
    *sum1 = 0;
    *sum2 = 0;
    int reverserow;

    for (i=0;i<colSize;i++)
    {
        reverserow = rowSize-1-i;
        *sum1 += ar[i][i];
        *sum2 += ar[i][reverserow];
    }
}
