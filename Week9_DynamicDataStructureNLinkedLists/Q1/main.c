// CX1007 Data Structures
// Week 9 Lab Tutorial - DynamicData-Linked Lists
// Solution for Q1

#include "stdlib.h"
#include "stdio.h"

////////////////////////////////////////////////////////////

void insert(char *s,int n);
void removes(char *s, int n);

//////////////////////////////////////////////////////////
void main ()
{
	int n;
    char *s;
	int choice;


	printf("How many characters do you want to input:");
	scanf("%d", &n);

	s=(char *)malloc((n+1)*sizeof(char));

    if (s==NULL)
	{
		printf("can't allocate the memory!");
		return;
	}

	printf("Input the string:");
	scanf("%s",s);

	printf("The string is %s\n", s);

	do
	{
		printf("Do you want to 1-insert or 2-remove or 3-quit?:");
		scanf("%d",&choice);
		//getchar(); //to clear the return carriage in the buffer

		if (choice==1)
			insert(s,n);
		else if (choice==2)
			removes(s,n);
	}while (choice!=3);


}

//////////////////////////////////////////
void removes(char *s, int n)
{
	int i;

	for (i=0;i<n;i++)
		*(s+i)=*(s+i+1);

	printf("Resulting string:%s\n", s);

}

//////////////////////////////////////////
void insert(char *s, int n)
{
	int i;

	for(i=n-1;i>0;i--)
		*(s+i)=*(s+i-1);

	*(s+n)='\0';

	printf("What is the character you want to insert:");

	fflush(stdin);
	scanf("%c", s);

	printf("Resulting string:%s\n", s);
}
