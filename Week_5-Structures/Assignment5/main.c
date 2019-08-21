#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 5
typedef struct
{
   int nameCardID;
   char personName[20];
   char companyName[20];
} NameCard;

void listNameCards(NameCard ncHolder[], int numCards);
void addNameCard(NameCard ncHolder[], NameCard newCard, int *numCards);
void removeNameCard(NameCard ncHolder[], char *target, int *numCards);
void getNameCard(NameCard ncHolder[], char *target, int numCards);

void sortNameCards(NameCard ncHolder[], int *numCards);
char *strlwr(char *str);
char *ltrim(char *str);
char *rtrim(char *str);
char *trim(char *str);

int main()
{
   NameCard ncHolder[MAX], newCard;
   char target[20], dummychar;
   int choice, i, numCards=0;

   printf("NTU NAME CARD HOLDER MANAGEMENT PROGRAM: \n");
   printf("1: listNameCards()\n");
   printf("2: addNameCard()\n");
   printf("3: removeNameCard()\n");
   printf("4: getNameCard()\n");
   printf("5: quit\n");
   do {
      printf("Enter your choice: \n");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            printf("listNameCards(): \n");
            listNameCards(ncHolder, numCards);
            break;
         case 2:
            printf("Enter nameCardID: \n");
            scanf("%d", &newCard.nameCardID);
            scanf("%c", &dummychar);
            printf("Enter personName: \n");
            gets(newCard.personName);
            printf("Enter companyName: \n");
            gets(newCard.companyName);
            addNameCard(ncHolder, newCard, &numCards);
            break;
         case 3:
            scanf("%c", &dummychar);
            printf("Enter personName:\n");
            gets(target);
            removeNameCard(ncHolder, target, &numCards);
            break;
         case 4:
            scanf("%c", &dummychar);
            printf("Enter personName: \n");
            gets(target);
            getNameCard(ncHolder, target, numCards);
            break;
      }
   } while (choice < 5);
   return 0;
}

// Own functions

// sortNameCards()
void sortNameCards(NameCard ncHolder[], int *numCards)
{
    NameCard temp;
    int i,j;

    if (*numCards<2)
        return;
    else
    {
        for (i=*numCards;i>0;i--)
        {
            for (j=0;j<(i-1);j++)
            {
                if (ncHolder[j].nameCardID>ncHolder[j+1].nameCardID)
                {
                    temp = ncHolder[j];
                    ncHolder[j] = ncHolder[j+1];
                    ncHolder[j+1] = temp;
                }
            }
        }
    }
}

char *strlwr(char *str)
{
    unsigned char *p = (unsigned char *)str;

    while (*p)
        {
            *p = tolower((unsigned char)*p);
            p++;
        }

    return str;
}

// ltrim()
char *ltrim(char *str)
{
    char seps[] = "\t\n\v\f\r ";

    int totrim = strspn(str, seps);
    if (totrim > 0)
    {
        size_t len = strlen(str);
        if (totrim == len)
        {
            str[0] = '\0';
        }
        else
        {
            memmove(str, str + totrim, len + 1 - totrim);
        }
    }
    return str;
}

// rtrim()
char *rtrim(char *str)
{
    int i;
    char seps[] = "\t\n\v\f\r ";

    i = strlen(str) - 1;
    while (i >= 0 && strchr(seps, str[i]) != NULL)
    {
        str[i] = '\0';
        i--;
    }
    return str;
}

// trim()
char *trim(char *str)
{
    return ltrim(rtrim(str));
}

// Assignment Functions
void listNameCards(NameCard ncHolder[], int numCards)
{
    int i;

    if (numCards==0)
    {
        printf("The ncHolder is empty \n");
    }
    else
    {
        for (i=0;i<numCards;i++)
        {
            printf("nameCardID: %d \n", ncHolder[i].nameCardID);
            printf("personName: %s \n", ncHolder[i].personName);
            printf("companyName: %s \n", ncHolder[i].companyName);
        }
    }
}

void addNameCard(NameCard ncHolder[], NameCard newCard, int *numCards)
{
    int newindex = *numCards;
    int i=0;
    int sameid = 0;
//    int *ptr = &newCard;

//    ptr->name is the same as (*ptr).name

    while(i<newindex)
    {
        if (ncHolder[i].nameCardID==newCard.nameCardID)
        {
            sameid = 1;
        }
        i++;
    }

    if (sameid==1)
    {
        printf("nameCardID has existed already! Enter another name card \n");
    }
    else
    {
        if (*numCards==MAX)
        {
            printf("Sorry! The ncHolder is full \n");
        }
        else
        {
        ncHolder[newindex].nameCardID = newCard.nameCardID;
        strcpy(ncHolder[newindex].personName, newCard.personName);
        strcpy(ncHolder[newindex].companyName, newCard.companyName);

        printf("The name card has been added successfully \n");

        (*numCards)++;
        sortNameCards(ncHolder, numCards);
        }
    }
}

void removeNameCard(NameCard ncHolder[], char *target, int *numCards)
{
    int i, different = 1, j;
    char name[20];

    if (*numCards==0)
    {
        printf("removeNameCard(): The ncHolder is empty \n");
        return;
    }

    for (i=0;i<*numCards;i++)
    {
        strcpy(name, trim(ncHolder[i].personName));
        different = strcmp(trim(strlwr(target)), strlwr(name));

        if (different==0)
        {
            printf("The name card is removed \n");
            printf("nameCardID: %d \n", ncHolder[i].nameCardID);
            printf("personName: %s \n", ncHolder[i].personName);
            printf("companyName: %s \n", ncHolder[i].companyName);

            for (j=i;j<(*numCards)-1;j++)
            {
                ncHolder[j] = ncHolder[j+1];
            }

            (*numCards)--;
            return;
        }
    }
    printf("The target person name is not in ncHolder \n");
}

void getNameCard(NameCard ncHolder[], char *target, int numCards)
{
    int i, different = 1, j;
    char name[20];

    if (numCards==0)
    {
        printf("The target person name is not found \n");
        return;
    }

    for (i=0;i<numCards;i++)
    {
        strcpy(name, trim(ncHolder[i].personName));
        different = strcmp(trim(strlwr(target)), strlwr(name));

        if (different==0)
        {
            printf("The target person name is found \n");
            printf("nameCardID: %d \n", ncHolder[i].nameCardID);
            printf("personName: %s \n", ncHolder[i].personName);
            printf("companyName: %s \n", ncHolder[i].companyName);

            return;
        }
    }
    printf("The target person name is not found \n");
}
