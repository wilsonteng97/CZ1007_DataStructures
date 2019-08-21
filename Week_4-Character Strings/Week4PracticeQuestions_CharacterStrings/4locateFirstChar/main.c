#include <stdio.h>
int locateLastChar(char *str, char ch);

int main()
{
    char str[40], ch;

    printf("Enter a string: \n");
    gets(str);
    printf("Enter the target character: \n");
    scanf("%c", &ch);
    printf("locateLastChar(): %d \n", locateLastChar(str, ch));
    return 0;
}

int locateLastChar(char *str, char ch)
{
    int i, located = 0, index;
    for (i=0;i<strlen(str);i++)
    {
        if (str[i]==ch)
        {
            located = 1;
            break;
        }
    }
    if (located==1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
