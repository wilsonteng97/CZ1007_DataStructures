#include <stdio.h>
#include <string.h>
#define N 20
char *longestStrInAr(char str[N][40], int size, int *length);

int main()
{
    char i, size, length;
    char str[N][40], first[40], last[40], *p;
    char dummychar;

    printf("Enter array size: \n");
    scanf("%d", &size);
    scanf("%c", &dummychar);
    for (i=0;i<size;i++)
    {
        printf("Enter string %d: \n", i+1);
        gets(str[i]);
    }
    p = longestStrInAr(str, size, &length);
    printf("longest: %s \nlength: %d \n", p, length);
    return 0;
}

char *longestStrInAr(char str[N][40], int size, int *length)
{
    int i = 0;
    *length = strlen(str[0]);

    while (i<size)
    {
        if (strlen(str[i])>(*length))
        {
            *length = strlen(str[i]);
        }
        i++;
    }

    i = 0;
    while (i<size)
    {
        if (strlen(str[i])==(*length))
        {
            return str[i];
        }
        i++;
    }
}
