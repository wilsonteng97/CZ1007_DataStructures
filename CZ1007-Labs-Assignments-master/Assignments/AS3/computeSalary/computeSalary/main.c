//
//  main.c
//  computeSalary
//
//  Created by Prem Adithya on 3/9/18.
//  Copyright © 2018 Prem Adithya. All rights reserved.
//

#include <stdio.h>

void readInput(int *id, int *noOfHours, int *payRate);
void printOutputs(int id, double grossPay);
double computeSalary1(int noOfHours, int payRate);
void computeSalary2(int noOfHours, int payRate, double *grossPay);

int main()
{
    int id = -1, noOfHours, payRate;
    double grossPay;
    readInput(&id, &noOfHours, &payRate);
    while  (id != -1) {
        printf("computeSalary1(): ");
        grossPay = computeSalary1(noOfHours, payRate);
        printOutputs(id, grossPay);
        printf("computeSalary2(): ");
        computeSalary2(noOfHours, payRate, &grossPay);
        printOutputs(id, grossPay);
        readInput(&id, &noOfHours, &payRate);
    }
    return 0;
}
void readInput(int *id, int *noOfHours, int *payRate)
{
    printf("Enter ID (-1 to end):\n");
    scanf("%d", id);
    
    if (*id != -1)
    {
        printf("Enter number of hours:\n");
        scanf("%d", noOfHours);
        
        printf("Enter hourly pay rate:\n");
        scanf("%d", payRate);
    }
}
void printOutputs(int id, double grossPay)
{
    printf("ID %d grossPay %.2lf\n", id, grossPay);
}
double computeSalary1(int noOfHours, int payRate)
{
    double pay = 0.0;
    
    if (noOfHours <= 160)
        pay = payRate * noOfHours;
    
    if (noOfHours > 160)
        pay = payRate * 1.5 * (noOfHours - 160) + (payRate * 160);
    
    return pay;
}
void computeSalary2(int noOfHours, int payRate, double *grossPay)
{
    *grossPay = computeSalary1(noOfHours, payRate);
}
