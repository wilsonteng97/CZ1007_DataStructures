//
//  main.c
//  Speed
//
//  Created by Prem Adithya on 16/8/18.
//  Copyright © 2018 Prem Adithya. All rights reserved.
//

#include <stdio.h>

int main() {
    float time, distance, speed;
    
    printf("Enter distance (in km): \n");
    scanf("%f", &distance);
    printf("Enter time (in sec): \n");
    scanf("%f", &time);
    
    speed = distance / time;
    
    printf("The speed is %.2f km/sec\n", speed);
    
    return 0;
}
