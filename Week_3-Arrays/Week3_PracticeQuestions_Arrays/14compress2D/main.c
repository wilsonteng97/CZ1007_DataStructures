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
    int i, j, count;
    int val;

    for (i=0;i<colSize;i++)
    {
        val = *(*(data + i) + 0);
        count = 0;

        for (j=0;j<rowSize;j++)
        {
            if (data[i][j]==val)
            {
                count++;
            }
            else
            {
                printf("%d ", val);
                printf("%d ", count);
                count = 1;
                val = data[i][j];
            }
        }
        printf("%d ", val);
        printf("%d ", count);
        printf("\n");
    }
}
