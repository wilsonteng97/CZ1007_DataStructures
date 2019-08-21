#include <stdio.h>
#include <string.h>
#include <ctype.h>
void cipher(char *s);
void decipher(char *s);
int main()
{
    char str[80];

    printf("Enter the string: \n");
    gets(str);
    printf("To cipher: %s -> ", str);
    cipher(str);
    printf("%s\n", str);
    printf("To decipher: %s -> ", str);
    decipher(str);
    printf("%s\n", str);
    return 0;
}
void cipher(char *s)
{
    /* Write your program code here */
    while (*s != '\0')
    {
        if (isalpha(*s))
            if (*s == 'z')
                *s = 'a';
            else if (*s == 'Z')
                *s = 'A';
            else
                (*s)++;
        s++;
    }
}
void decipher(char *s)
{
    /* Write your program code here */
    while (*s != '\0')
    {
        if (isalpha(*s))
            if (*s == 'a')
                *s = 'z';
            else if (*s == 'A')
                *s = 'Z';
            else
                (*s)--;
        s++;
    }
}
