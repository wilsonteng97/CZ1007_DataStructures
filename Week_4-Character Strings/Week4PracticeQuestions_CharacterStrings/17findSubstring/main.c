#include <stdio.h>
#define INIT_VALUE -1
int findSubstring(char *str, char *substr);

int main()
{
    char str[40], substr[40];
    int result = INIT_VALUE;

    printf("Enter the string: \n");
    gets(str);
    printf("Enter the substring: \n");
    gets(substr);
    result = findSubstring(str, substr);
    if (result == 1)
        printf("findSubstring(): Is a substring\n");
    else if ( result == 0)
        printf("findSubstring(): Not a substring\n");
    else
        printf("findSubstring(): An error\n");
    return 0;
}

int findSubstring(char *str, char *substr)
{
    int result = -1;
    char *s1=str, *s2=substr;

    while (*s1)
    {
        if (*s1 == *s2)
        {
            result = 1;
            s1++;
            s2++;
        }
        else
        {
            result = 0;
            s1++;
            s2 = substr;
        }

        if (*s2=='\0'&&result==1)
        {
            return 1;
        }
    }
    return 0;
}
