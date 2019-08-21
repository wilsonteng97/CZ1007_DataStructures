//
//  main.c
//  maxCharToFront
//
//  Created by Prem Adithya on 20/9/18.
//  Copyright © 2018 Prem Adithya. All rights reserved.
//

#include <stdio.h>
void maxCharToFront(char *str);
int main()
{
    char str[80];
    
    printf("Enter a string: \n");
    gets(str);
    printf("maxCharToFront(): ");
    maxCharToFront(str);
    puts(str);
    return 0;
}
void maxCharToFront(char *str)
{
    /* Write your code here */
    char max = 'a';
    int count = 0, pos = 0;
    
    while(*(str + count))
    {
        if (*(str + count) > max)
        {
            max = *(str + count);
            pos = count;
        }
        
        count++;
    }
    
    while(*(str + pos) && pos > 0)
    {
        *(str + pos) = *(str + pos - 1);
        pos--;
    }
    
    *str = max;
}
