#include <stdio.h>
void processString(char *str, int *totVowels, int *totDigits);

int main()
{
    char str[50];
    int totVowels=0, totDigits=0;

    printf("Enter the string: \n");
    gets(str);
    processString(str, &totVowels, &totDigits);
    printf("Total vowels = %d\n", totVowels);
    printf("Total digits = %d\n", totDigits);
    return 0;
}

void processString(char *str, int *totVowels, int *totDigits)
{
    int i=0,j;
    char vowels[5] = "aeiou";

    while(str[i]!='\0')
    {
        if (isdigit(str[i]))
        {
            (*totDigits)++;
        }
        else
        {
            if (strchr(vowels, tolower(str[i])))
            {
                (*totVowels)++;
            }
        }
        i++;
    }
}
