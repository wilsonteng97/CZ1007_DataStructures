#include <stdio.h>
#include <ctype.h>
#include <string.h>
void processString(char *str, int *totVowels, int *totDigits);
int main()
{
    char str[50];
    int totVowels, totDigits;
    printf("Enter the string: \n");
    gets(str);
    processString(str, &totVowels, &totDigits);
    printf("Total vowels = %d\n", totVowels);
    printf("Total digits = %d\n", totDigits);
    return 0;
}
void processString(char *str, int *totVowels, int *totDigits)
{
    /* Write your program code here */
    int i = 0;
    *totVowels = 0;
    *totDigits = 0;
    char vowels[] = "AEIOUaeiou";

    while (*str != '\0')
    {
        if (strchr(vowels, *str))
            ++*totVowels;
        if (isdigit(*str))
            ++*totDigits;
        str++;
    }
}
