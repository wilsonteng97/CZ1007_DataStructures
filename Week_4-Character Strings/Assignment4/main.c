#include <stdio.h>
#include <string.h>
#include <ctype.h>
void createTable(char lookupTable[26][26]);
void printTable(char lookupTable[26][26]);
void encrypt(char lookupTable[26][26], char keyword[20], char *plaintext, char *ciphertext);
void decrypt(char lookupTable[26][26], char keyword[20], char *plaintext, char *ciphertext);

int main()
{
   int choice;
   char keyword[20];
   char table[26][26];
   char plaintext[80], ciphertext[80];

   printf("ENCRYPTION PROGRAM \n");
   printf("1: createTable()\n");
   printf("2: printTable()\n");
   printf("3: enter a new keyword\n");
   printf("4: encrypt() a plaintext message \n");
   printf("5: decrypt() a ciphertext message \n");
   printf("6: quit \n");
   do {
      printf("Enter your choice: \n");
      scanf("%d", &choice);
      switch(choice) {
         case 1:
            createTable(table);
            printf("createTable() done \n");
            break;
         case 2:
            printf("printTable(): \n");
            createTable(table);
            printTable(table);
            break;
         case 3:
            printf("Enter a new keyword: \n");
            scanf("%s", keyword);
            break;
         case 4:
            printf("Enter a plaintext: \n");
            scanf("%s", plaintext);
            encrypt(table, keyword, plaintext, ciphertext);
            printf("plaintext: %s\n", plaintext);
            printf("ciphertext: %s\n", ciphertext);
            break;
         case 5:
            printf("Enter a ciphertext: \n");
            scanf("%s", ciphertext);
            decrypt(table, keyword, plaintext, ciphertext);
            printf("ciphertext: %s\n", ciphertext);
            printf("plaintext: %s\n", plaintext);
            break;
         default:
            break;
      }
   } while (choice < 6);
   return 0;
}

void printTable(char lookupTable[26][26])
{
   int row, col;
   char c='a';

   printf(" ");printf(" ");
   for (row = 0; row < 26; ++row) {
      printf("%c ",c); c=c+1;
   }
   printf("\n");
   c='a';
   for (row = 0; row < 26; ++row) {
      printf("%c ",c); c=c+1;
      for (col = 0; col < 26; ++col) {
         printf("%c ", lookupTable[row][col]);
      }
      printf("\n");
   }
}

void createTable(char lookupTable[26][26])
{
    int i, j;
    char c;
    int limit;

    limit = 'A' + 25;

    for (i=0;i<26;i++)
    {
        c = 'A' + i;

        for (j=0;j<26;j++)
        {
            lookupTable[i][j] = c;
            c++;
            if (c>limit)
            {
                c = 'A';
            }
        }
    }
}

void encrypt(char lookupTable[26][26], char keyword[20], char *plaintext, char *ciphertext)
{
    int i;
    int p, c;

    for (i=0;i<strlen(plaintext);i++)
    {
        p = (int)(toupper(plaintext[i])) - (int)('A');

        c = ((i+1) % strlen(keyword))-1;

//        in case current plaintext index % strlen of keyword == 0
        if (c<0)
        {
            c = strlen(keyword) - 1;
        }

        c = (int)(toupper(keyword[c])) - (int)('A');
        *(ciphertext + i) = lookupTable[p][c];
    }
//    cipherext[strlen(plaintext)] = '\0';
    int len = strlen(plaintext);
    *(ciphertext + len) = '\0';
}

void decrypt(char lookupTable[26][26], char keyword[20], char *plaintext, char *ciphertext)
{
    int count;
    int index;
    int i, j;

    for (count=0;count<strlen(ciphertext);count++)
    {
        if(count<strlen(keyword))
        {
            index = count;
        }
        else if (((count+1)%strlen(keyword))!=0)
        {
            index = (count+1)%strlen(keyword) - 1;
        }
        else
        {
            index = strlen(keyword) - 1;
        }

        i = (int)(toupper(keyword[index])) - (int)('A');
        j = 0;
        while (lookupTable[i][j]!=ciphertext[count])
        {
            j++;
        }
        j += (int)('a');
        *(plaintext + count) = (char)j;
    }
    plaintext[strlen(ciphertext)] = '\0';
}
