#include <stdio.h>
int countSubstring(char str[], char substr[]);
int main()
{
    char str[80], substr[80];

    printf("Enter the string: \n");
    gets(str);
    printf("Enter the substring: \n");
    gets(substr);
    printf("countSubstring(): %d \n", countSubstring(str, substr));
    return 0;
}

int countSubstring(char str[], char substr[])
{
    char *s1 = str, *s2 = substr;
    int result=0, count=0;

//    if (strstr(str, substr))
//    {
        while (*s1)
        {
            if (*s1==*s2)
            {
                result = 1;
                s1++;
                s2++;
            }
            else
            {
                result = 0;
                s1++;
                s2 = substr;
            }

            if (*s2=='\0'&&result==1)
            {
                count++;
                s2 = substr;
            }
        }
//    }
//    else
//    {
//        return 0;
//    }
    return count;
}
