#include <stdio.h>
int main()
{
    int total, count, lines, input;
    double average;
    int i;

    printf("Enter number of lines: \n");
    scanf("%d", &lines);

    for (i=1; i<=lines; i++)
    {
        count = 0;
        total = 0;
        input = 0;

        printf("Enter line %d (end with -1): \n", i);
        while (1)
        {
            scanf("%d", &input);

            if (input == -1)
                break;

            total += input;
            count++;
        }
        average = (float) total / count;
        printf("Average = %.2f \n \n", average);
    }

    return 0;
}
