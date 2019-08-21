#include <stdio.h>
#include <ctype.h>
void convertCaseStr(char *str);

int main()
{
    char str[80];

    printf("Enter the string: \n");
    gets(str);
    convertCaseStr(str);
    printf("convertCaseStr(): %s \n", str);
    return 0;
}

void convertCaseStr(char *str)
{
    int offset = 'a' - 'A';
    char ch;

    for (int i=0;i<strlen(str);i++)
    {
        ch = str[i];
        if (ch>='A'&&ch<='Z')
        {
            str[i] = (str[i] + offset);
        }
        else if (ch>='a'&&ch<='z')
        {
            str[i] = (str[i] - offset);
        }
    }
}
