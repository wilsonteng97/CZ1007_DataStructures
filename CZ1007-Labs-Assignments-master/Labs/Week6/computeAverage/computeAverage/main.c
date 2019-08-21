//
//  main.c
//  computeAverage
//
//  Created by Prem Adithya on 21/9/18.
//  Copyright © 2018 Prem Adithya. All rights reserved.
//

#include <stdio.h>
#include <string.h>
struct student{
    char name[20]; /* student name */
    double testScore; /* test score */
    double examScore; /* exam score */
    double total; /* total = (testScore+examScore)/2 */
};
double average();
int main()
{
    printf("average(): %.2f\n", average());
    return 0;
}
double average()
{
    /* Write your program code here */
    struct student std[50];
    int i = 0;
    float sum = 0;
    
    while (1)
    {
        printf("Enter student name:\n");
        gets(std[i].name);
        
        if (strcmp(std[i].name, "END") == 0)
            break;
        
        printf("Enter test score:\n");
        scanf("%lf", &std[i].testScore);
        
        printf("Enter exam score:\n");
        scanf("%lf", &std[i].examScore);
        
        std[i].total = (std[i].testScore + std[i].examScore) / 2;
        printf("Student %s total = %.2lf\n", std[i].name, std[i].total);
        
        getchar(); // consume new line
        
        i++;
    }
    
    for (int j = i; j >= 0; j--)
    {
        sum += std[j].total;
    }
    
    return sum / i;
}
