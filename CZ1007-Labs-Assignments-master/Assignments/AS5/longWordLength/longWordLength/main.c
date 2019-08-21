//
//  main.c
//  longWordLength
//
//  Created by Prem Adithya on 20/9/18.
//  Copyright © 2018 Prem Adithya. All rights reserved.
//

#include <stdio.h>
int longWordLength(char *s);
int main()
{
    char str[80];
    printf("Enter a string: \n");
    gets(str);
    printf("longWordLength(): %d\n", longWordLength(str));
    return 0;
}
int longWordLength(char *s)
{
    /* Write your code here */
    int count = 0, max = 0;
    
    while (*s)
    {
        if (*s != ' ' && (('a' <= *s && *s <= 'z') || ('A' <= *s && *s <= 'Z')))
        {
            count++;
        }
        else
        {
            if (max < count)
            {
                max = count;
            }
            count = 0;
        }
        
        s++;
    }
    
    return max;
}
