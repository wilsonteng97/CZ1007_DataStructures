#include <stdio.h>
char *stringncpy(char *s1, char *s2, int n);
int main()
{
    char sourceStr[40], targetStr[40], *target;
    int length;
    printf("Enter the string: \n");
    gets(sourceStr);
    printf("Enter the number of characters: \n");
    scanf("%d", &length);
    target = stringncpy(targetStr, sourceStr, length);
    printf("stringncpy(): %s\n", target);
    return 0;
}
char *stringncpy(char *s1, char *s2, int n)
{
    /* Write your program code here */
    char *p1, *p2;
    p1 = s1;
    p2 = s2;

    while (n > 0)
    {
        if (*p2 == '\0')
        {
            *p1 = '\0';
        }
        else
        {
            *p1 = *p2;
            ++p2;
        }
        ++p1;
        n--;
    }

    return s1;
}
