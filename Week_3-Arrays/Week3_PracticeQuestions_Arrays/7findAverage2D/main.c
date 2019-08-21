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
        {
            scanf("%f", &ar[i][j]);
        }
    }
    findAverage2D(ar);
    printf("findAverage2D(): :\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%.2f ", ar[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void findAverage2D(float matrix[4][4])
{
    int i, j;
    float sum;

    for (i=0;i<4;i++)
    {
        sum = 0;
        for (j=0;j<3;j++)
        {
            sum += matrix[i][j];
        }
        matrix[i][3] = sum/3;
    }
}
