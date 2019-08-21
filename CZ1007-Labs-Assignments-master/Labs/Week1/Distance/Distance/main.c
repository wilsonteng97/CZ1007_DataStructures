//
//  main.c
//  Distance
//
//  Created by Prem Adithya on 16/8/18.
//  Copyright © 2018 Prem Adithya. All rights reserved.
//

#include <stdio.h>
#include <Math.h>

int main() {
    float x1, x2, y1, y2, distance;
    
    printf("Enter the first point x1 y1: \n");
    scanf("%f %f", &x1, &y1);
    
    printf("Enter the second point x2 y2: \n");
    scanf("%f %f", &x2, &y2);
    
    distance = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
    
    printf("The distance is %.2f\n", distance);
    
    return 0;
}
