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
    while (*s)
    {
        if (isalpha(*s))
        {
            *s += 1;
            if (*s=='z'+1)
            {
                *s = 'a';
            }
            if (*s=='Z'+1)
            {
                *s = 'A';
            }
        }
        s++;
    }
}

void decipher(char *s)
{
    while (*s)
    {
        if (isalpha(*s))
        {
            *s -= 1;
            if (*s=='a'-1)
            {
                *s = 'z';
            }
            if (*s=='A'-1)
            {
                *s = 'Z';
            }
        }
        s++;
    }
}
