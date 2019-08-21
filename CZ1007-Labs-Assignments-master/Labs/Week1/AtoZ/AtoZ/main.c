//
//  main.c
//  AtoZ
//
//  Created by Prem Adithya on 16/8/18.
//  Copyright © 2018 Prem Adithya. All rights reserved.
//

#include <stdio.h>
int main()
{
    char loop;
    printf("Print A-Z alphabets: ");
    for (loop='A'; loop<='Z'; loop++) {
    putchar(loop);
    }
    return 0;
}
