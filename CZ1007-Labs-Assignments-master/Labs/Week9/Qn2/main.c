// CX1007 Data Structures
// Week 9 Lab Tutorial - DynamicData-Linked Lists

#include "stdlib.h"
#include "stdio.h"

////////////////////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;

int main()
{
	ListNode *head, *p, *temp;
	int n;

	head=NULL;
	p=NULL;		// pointing to the last node in the list
	printf("Enter a list of numbers, terminated by a non-digit character:\n");

    //Write your program code here

    while (scanf("%d", &n))
    {
        if (head == NULL)
        {
            head = malloc(sizeof(ListNode));
            p = head;
        }
        else
        {

            p->next = malloc(sizeof(ListNode));
            p = p->next;
        }
        p->item = n;
        p->next = NULL;
    }

    printf("Current list: ");

    p = head;

    while (p != NULL)
    {
        printf("%d ", p->item);
        p = p->next;
    }

    printf("\n");

	p = head;
	while (p!= NULL) {
		temp=p->next;
		free(p);
		p=temp;
	}

	return 0;
}
