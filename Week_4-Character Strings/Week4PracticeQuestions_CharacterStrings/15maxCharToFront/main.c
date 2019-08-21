#include <stdio.h>
#include <string.h>
void maxCharToFront(char *str);

int main()
{
    char str[80];

    printf("Enter a string: \n");
    gets(str);
    printf("maxCharToFront(): ");
    maxCharToFront(str);
    puts(str);
    return 0;
}

void maxCharToFront(char *str)
{
    int i = 0;
    char maxchar = str[0];
    int maxindex = 0;

    while (i<strlen(str))
    {
        if (str[i]>maxchar)
        {
            maxchar = str[i];
            maxindex = i;
        }
        i++;
    }

    for (i=maxindex;i>0;i--)
    {
        str[i] = str[i-1];
    }

    str[0] = maxchar;
}
