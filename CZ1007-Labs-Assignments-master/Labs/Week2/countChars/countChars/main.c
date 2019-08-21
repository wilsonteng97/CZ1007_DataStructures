//
//  main.c
//  countChars
//
//  Created by Prem Adithya on 23/8/18.
//  Copyright © 2018 Prem Adithya. All rights reserved.
//

#include <stdio.h>
int main()
{
    int ccount = 0, dcount = 0;
    char ch;
    printf("Enter your characters (# to end): \n");
    
    while (ch != '#')
    {
        if (isalpha(ch))
             ccount++;
        if (isnumber(ch))
            dcount++;
        
        scanf("%c", &ch);
    }
    
    printf("The number of digits: %d\n", dcount);
    printf("The number of letters: %d\n", ccount);
    return 0;
}
