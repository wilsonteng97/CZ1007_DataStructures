#include <stdio.h>
int countSubstring(char str[], char substr[]);
int main()
{
    char str[80],substr[80];

    printf("Enter the string: \n");
    gets(str);
    printf("Enter the substring: \n");
    gets(substr);
    printf("countSubstring(): %d\n", countSubstring(str, substr));
    return 0;
}
int countSubstring(char str[], char substr[])
{
    /* Write your program code here */
    char *p1, *p2;
    p1 = str;
    p2 = substr;
    int contains = 0;
    int num = 0;

    while (*p1 != '\0')
    {
        if (*p1 == *p2)
        {
            p1++;
            p2++;
            contains = 1;
        }
        else if (contains == 1 && *p2 == '\0')
        {
            p2 = substr;
            num++;
        }
        else if (contains == 0 && *p2 == '\0')
        {
            return num;
        }
        else
        {
           p1++;
        }
    }
}
