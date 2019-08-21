//
//  main.c
//  Cylinder
//
//  Created by Prem Adithya on 16/8/18.
//  Copyright © 2018 Prem Adithya. All rights reserved.
//

#include <stdio.h>

int main() {
    float r, h, volume, area;
    const float pi = 3.14159265359;
    
    printf("Enter the radius: \n");
    scanf("%f", &r);
    printf("Enter the height: \n");
    scanf("%f", &h);
    
    volume = pi * r * r * h;
    area = 2 * pi * r * h + 2 * pi * r * r;
    
    printf("The volume is: %.2f\n", volume);
    printf("The surface area is: %.2f\n", area);
    
    return 0;
}
