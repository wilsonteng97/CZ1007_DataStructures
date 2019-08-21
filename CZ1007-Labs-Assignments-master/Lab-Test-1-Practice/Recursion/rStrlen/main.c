#include <stdio.h>
int rStrLen(char *s);
int main()
{
    char str[80];
    printf("Enter the string: \n");
    gets(str);
    printf("rStrLen(): %d\n", rStrLen(str));
    return 0;
}
int rStrLen(char *s)
{
    /* Write your program code here */
    char *p;
    p = s;

    if (*p != '\0')
        return 1 + rStrLen(++p);
    else
        return 0;
}
