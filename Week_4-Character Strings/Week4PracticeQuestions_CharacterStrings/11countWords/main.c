#include <stdio.h>
//#include <string.h>
int countWords(char *s);

int main()
{
    char str[50];

    printf("Enter the string: \n");
    gets(str);
    printf("countWords(): %d", countWords(str));
    return 0;
}

int countWords(char *s)
{
    int count = 1;

    if (strlen(s)==0)
    {
        return 0;
    }

    while(*s)
    {
        if (isspace(*s))
        {
            count++;
        }
        s++;
    }
    return count;
}
