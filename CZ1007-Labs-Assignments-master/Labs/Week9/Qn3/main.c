// CX1007 Data Structures
// Week 9 Lab Tutorial - DynamicData-Linked Lists

#include "stdlib.h"
#include "stdio.h"

////////////////////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;

//////////////////////////////////////////////////////
void deleteList(ListNode **p);
//////////////////////////////////////////////////////

int main()
{
	ListNode *head, *p, *temp;
	int n;

	head=NULL;
	p=NULL;		// pointing to the last node in the list
	printf("Enter a list of numbers, terminated by a non-digit character:\n");

	//begin to build the linked list
	while (scanf("%d", &n))
	{
		if (head==NULL)
		{
			head=(ListNode *)malloc(sizeof(ListNode));
			p=head;
		}
		else
		{
			p->next=(ListNode *)malloc(sizeof(ListNode));
			p=p->next;
		}
		p->item=n;
		p->next=NULL;

	} //end of building the list
    scanf("%*s");
	//print the items of the current linked list.
	printf("Current list:");
	p=head;
	while (p!=NULL)
	{
		printf("%d ",p->item);
		p=p->next;
	}
	printf("\n");

	deleteList(&head);
	//p = head;
	//while (p!= NULL) {
	//	temp=p->next;
	//	free(p);
	//	p=temp;
	//}
	return 0;

}
void deleteList(ListNode **p)
{
    //Write your program code here.
    if (*p != NULL)
    {
        deleteList(&(*p)->next);
        free(*p);
        *p = NULL;
    }
}
////////////////////////////////////////////////////////////
