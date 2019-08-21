#include <stdio.h>
void delNum(char *str);

int main()
{
    char str[80];

    printf("Enter a string: \n");
    gets(str);
    delNum(str);
    printf("delNum(): %s", str);
    return 0;
}

void delNum(char *str)
{
    int i=0,j;

    while (str[i]!='\0')
    {
        if (isdigit(str[i]))
        {
            for (j=i;j<strlen(str);j++)
            {
                str[j] = str[j+1];
            }
            continue;
        }
        i++;
    }
}
