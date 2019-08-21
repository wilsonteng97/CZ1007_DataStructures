#include <stdio.h>
void findAverage2D(float matrix[4][4]);
int main()
{
    float ar[4][4];
    int i,j;

    printf("Enter data: \n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            scanf("%f", &ar[i][j]);
    }
    findAverage2D(ar);
    printf("findAverage2D(): :\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%.2f ", ar[i][j]);
        printf("\n");
    }
    return 0;
}
void findAverage2D(float matrix[4][4])
{
    /* write your program code here */
    int row = 0;
    float sum, average;

    while (row < 4)
    {
        sum = matrix[row][0] + matrix[row][1] + matrix[row][2];
        average = sum / 3;
        matrix[row][3] = average;
        row++;
    }
}
