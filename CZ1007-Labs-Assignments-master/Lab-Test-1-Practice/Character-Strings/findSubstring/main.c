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
    /* Write your code here */
    int contains = 0;
    char *p1, *p2;
    p1 = str;
    p2 = substr;

    while (*p1 != '\0')
    {
        if (*p2 == *p1)
        {
            contains = 1;
            p1++;
            p2++;
        }
        else if (*p2 == '\0' && contains == 1)
        {
            return contains;
        }
        else
        {
            p1++;
            contains = 0;
        }
    }

    return 0;
}
