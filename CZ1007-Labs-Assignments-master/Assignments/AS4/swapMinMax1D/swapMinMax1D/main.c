//
//  main.c
//  swapMinMax1D
//
//  Created by Prem Adithya on 11/9/18.
//  Copyright © 2018 Prem Adithya. All rights reserved.
//

#include <stdio.h>
void swapMinMax1D(int ar[], int size);
int main()
{
    int ar[50],i,size;
    
    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0; i<size; i++)
        scanf("%d",ar+i);
    swapMinMax1D(ar, size);
    printf("swapMinMax1D(): ");
    for (i=0; i<size; i++)
        printf("%d ",*(ar+i));
    return 0;
}
void swapMinMax1D(int ar[], int size)
{
    /* Write your code here */
    int min = ar[0], max = ar[0], indexMin = 0, indexMax = 0;
    
    for (int i=0; i < size; i++)
    {
        if (ar[i] >= max)
        {
            max = ar[i];
            indexMax = i;
        }
        
        if (ar[i] <= min)
        {
            min = ar[i];
            indexMin = i;
        }
    }
    
    ar[indexMax] = min;
    ar[indexMin] = max;
}
