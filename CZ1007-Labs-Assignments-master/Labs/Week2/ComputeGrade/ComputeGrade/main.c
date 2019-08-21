//
//  main.c
//  ComputeGrade
//
//  Created by Prem Adithya on 23/8/18.
//  Copyright © 2018 Prem Adithya. All rights reserved.
//

#include <stdio.h>
int main()
{
    int studentNumber = 0, mark;
    printf("Enter Student ID: \n");
    scanf("%d", &studentNumber);
    while (studentNumber != -1)
    {
        printf("Enter Mark: ");
        scanf("%d", &mark);
        
        int intMark = round(mark/10.0);
        
        switch(intMark)
        {
            case 10:
            case 9:
            case 8:
                printf("Grade = A\n");
                break;
            case 7:
                printf("Grade = B\n");
                break;
            case 6:
                printf("Grade = C\n");
                break;
            case 5:
                printf("Grade = D\n");
                break;
            case 4:
                printf("Grade = F\n");
                break;
            default:
                printf("Grade = F\n");
                break;
        }
        printf("Enter Student ID: ");
        scanf("%d", &studentNumber);
    }
    return 0;
}
