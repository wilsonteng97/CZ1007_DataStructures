//
//  main.c
//  insertChar
//
//  Created by Prem Adithya on 20/9/18.
//  Copyright © 2018 Prem Adithya. All rights reserved.
//

#include <stdio.h>
void insertChar(char *str1, char *str2, char ch);
int main()
{
    char a[80],b[80];
    char ch;
    
    printf("Enter a string: \n");
    gets(a);
    printf("Enter a character to be inserted: \n");
    ch = getchar();
    insertChar(a,b,ch);
    printf("insertChar(): ");
    puts(b);
    return 0;
}
void insertChar(char *str1, char *str2, char ch)
{
    /* Write your code here */
    int str1Count = 0, offset = 0;
    
    while (1)
    {
        if (str1Count % 3 == 0 && str1Count != 0)
        {
            *(str2 + str1Count + offset) = ch;
            offset++;
        }
        
        *(str2 + str1Count + offset) = *(str1 + str1Count);
        
        if (*(str1 + str1Count) == '\0')
        {
            break;
        }
        
        str1Count++;
    }
}
