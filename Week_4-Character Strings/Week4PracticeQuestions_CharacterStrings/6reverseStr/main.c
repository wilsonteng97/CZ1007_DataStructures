#include <stdio.h>
#include <string.h>
void reverseStr(char *str);

int main()
{
    char str[80];

    printf("Enter a string; \n");
    gets(str);
    reverseStr(str);
    printf("reverseStr(): %s \n", str);
    return 0;
}

void reverseStr(char *str)
{
    int i,j;
    len = strlen(str);
    char temp;

    for (i=0, j=len-1;i<len/2;i++,j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
