// CX1007 Data Structures
// Week 9 Lab Tutorial - DynamicData-Linked Lists
// Q3

#include "stdlib.h"
#include "stdio.h"

////////////////////////////////////////////////////////////

typedef struct _listnode
{
    int item;
    struct _listnode *next;
} ListNode;

//////////////////////////////////////////////////////

int searchList(ListNode *head, int value);

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

    //search for a value in the list. Q3
    printf("Enter value to search for:");
    scanf("%d", &n);
    searchList(head,n);

    p = head;
    while (p!= NULL)
    {
        temp=p->next;
        free(p);
        p=temp;
    }
    return 0;

}

////////////////////////////////////////////////////////////

int searchList(ListNode *head, int value)
{
    //Write your program code here
    return rSearchList(head, value, 0);
}


int rSearchList(ListNode *head, int value, int index)
{
    //Write your program code here
    if (head == NULL)
    {
        printf("Value %d cannot be found!\n", value);
        return -1;
    }
    else
    {
        if (head->item == value)
        {
            printf("Value %d found at index %d\n", value, index);
            return index;
        }
        else
        {
            return rSearchList(head->next, value, ++index);
        }
    }
}
