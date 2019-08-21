#include <stdio.h>

void insertChar(char *str1, char *str2, char ch);

int main()
{
    char a[80], b[80];
    char ch;

    printf("Enter a string: \n");
    gets(a);
    printf("Enter a character to be inserted: \n");
    ch = getchar();
    insertChar(a,b,ch);
    printf("insertChar(): ");
    puts(b);
    return 0;
}

void insertChar(char *str1, char *str2, char ch)
{
    int i=0, j=0;

    while (str1[i]!='\0')
    {
        if ((i+1)%3==0&&i!=0)
        {
            str2[j++] = str1[i++];
            str2[j++] = ch;
        }
        else
        {
            str2[j] = str1[i];
            i++;
            j++;
        }
    }
    str2[j] = '\0';
}
