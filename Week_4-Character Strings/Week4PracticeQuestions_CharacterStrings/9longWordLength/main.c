#include <stdio.h>
#include <ctype.h>
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
    int longest=0, current=0;

    while(*s!='\0') // while (*s) since while ('\0'0 discontinues loop
    {
        if (isalpha(*s))
        {
            current++;
        }
        else
        {
            current = 0;
        }

        if (current>longest)
        {
            longest = current;
        }
        s++;
    }
    return longest;
}
