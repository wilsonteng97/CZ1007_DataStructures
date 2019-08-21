#include <stdio.h>
typedef struct
{
    char source;
    char code;
} Rule;
void encodeChar(Rule table[5], char *s, char *t);
int main()
{
    char s[80],t[80];
    Rule table[5] = {'a','d', 'b','z', 'z','a', 'd','b', '\0','\0' };

    printf("Source string: \n");
    gets(s);
    encodeChar(table,s,t);
    printf("Encoded string: %s\n", t);
    return 0;
}
void encodeChar(Rule table[5], char *s, char *t)
{
    /* Write your program code here */
    int i, j, hit;

    for (i=0; i < 80; i++)
    {
        hit = 0;

        for (j=0; j < 5; j++)
        {
            if (s[i] == table[j].source)
            {
                t[i] = table[j].code;
                hit = 1;
            }
        }

        if (hit == 0)
        {
            t[i] = s[i];
        }
    }
}
