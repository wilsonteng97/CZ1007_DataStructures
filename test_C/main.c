#include <stdio.h>
#include <string.h>

int main () {
   char str[50];
   int i;

   printf("Enter a string : ");
   gets(str);
//   for (i=strlen(str);i>0;i--)
//   {
//       if (isspace(str[i])&&str[i-1]!=' ')
//            str[i] = '\0';
//   }
   printf("You entered: %s", str);
   printf("walao \n");
   printf("%d \n", strlen(str));
   printf("%d \n", strcmp(str, "hello"));


   return(0);
}
