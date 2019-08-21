#include <stdio.h>
int main()
{
    int studentNumber, mark;
    char grade;

    printf("Enter Student ID: ");
    scanf("%d", &studentNumber);
    while (studentNumber != -1)
    {
        printf("Enter Mark: ");
        scanf("%d", &mark);

        switch(mark/5)
        {
            case 20: case 19: case 17: case 16: case 15:
                grade = 'A'; break;
            case 14: case 13:
                grade = 'B'; break;
            case 12: case 11:
                grade = 'C'; break;
            case 10: case 9:
                grade = 'D'; break;
            default:
                grade = 'F';
        }
        printf("Grade = %c\n", grade);
        printf("Enter Student ID: ");
        scanf("%d", &studentNumber);
    }
    return 0;
}
