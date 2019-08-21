#include <stdio.h>
#include <string.h>
void mergeStr(char *a, char *b, char *c);
int main()
{
    char a[80],b[80];
    char c[80];
    printf("Enter the first string: \n");
    gets(a);
    printf("Enter the second string: \n");
    gets(b);
    mergeStr(a,b,c);
    printf("mergeStr(): ");
    puts(c);
    return 0;
}
void mergeStr(char *a, char *b, char *c)
{
    /* Write your code here */
    char *cStr, *origStr;
    char chr = 'a';
    cStr = c;

    strcat(b, a);

    //printf("%s", b);

    origStr = b;

    while (chr <= 'z')
    {
        origStr = b;

        while (*origStr != '\0')
        {
            if (chr == *origStr)
            {
                *cStr = chr;
                cStr++;
            }

            origStr++;
        }

        chr++;
    }
}
