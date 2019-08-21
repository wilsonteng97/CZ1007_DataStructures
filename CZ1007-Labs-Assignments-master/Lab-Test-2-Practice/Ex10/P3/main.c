// CX1007 Data Structures
// Week 10 P3

#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
    int item;
    struct _listnode *next;
} ListNode;

void printList(ListNode *cur);
ListNode * findNode(ListNode *cur, int index);
int insertNode(ListNode **ptrHead, int index, int item);
void deleteList(ListNode **ptrHead);

int combineAlternating(ListNode **ptrHead, ListNode *head1, ListNode *head2);

int main()
{
    ListNode *head1=NULL;
    ListNode *head2=NULL;
    ListNode *headFinal=NULL;
    int size1 =0;
    int size2 =0;
    int item;

    printf("Enter a list of numbers for head1, terminated by any non-digit character: \n");
    while(scanf("%d",&item))
        if(insertNode(&head1,size1, item)) size1++;
    scanf("%*s");

    printf("Enter a list of numbers for head2, terminated by any non-digit character: \n");
    while(scanf("%d",&item))
        if(insertNode(&head2,size2, item)) size2++;
    scanf("%*s");

    printf("\nBefore combineAlternating() is called:\n");
    printf("Head 1:\n");
    printList(head1);
    printf("Head 2:\n");
    printList(head2);

    combineAlternating(&headFinal,head1,head2);

    printf("\nAfter combineAlternating() was called:\n");
    printf("Head 1:\n");
    printList(head1);
    printf("Head 2:\n");
    printList(head2);
    printf("Combined List:\n");
    printList(headFinal);

    if(head1!=NULL)
        deleteList(&head1); //it will remove head2 linked list
    if(head2!=NULL)
        deleteList(&head2);
    if(headFinal!=NULL)
        deleteList(&headFinal);
    return 0;
}

void printList(ListNode *cur)
{
    printf("Current List: ");
    while (cur != NULL)
    {
        printf("%d ", cur->item);
        cur = cur->next;
    }
    printf("\n");
}

ListNode *findNode(ListNode* cur, int index)
{
    if (cur==NULL || index<0)
        return NULL;
    while(index>0)
    {
        cur=cur->next;
        if (cur==NULL)
            return NULL;
        index--;
    }
    return cur;
}

int insertNode(ListNode **ptrHead, int index, int item)
{
    ListNode  *pre, *newNode;
    // If empty list or inserting first node, update head pointer
    if (index == 0)
    {
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = *ptrHead;
        *ptrHead = newNode;
        return 1;
    }
    // Find the nodes before and at the target position
    // Create a new node and reconnect the links
    else if ((pre = findNode(*ptrHead, index-1)) != NULL)
    {
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = pre->next;
        pre->next = newNode;
        return 1;
    }
    return 0;
}

void deleteList(ListNode **ptrHead)
{
    ListNode *cur = *ptrHead;
    ListNode *temp;
    while (cur!= NULL)
    {
        temp=cur->next;
        free(cur);
        cur=temp;
    }
    *ptrHead=NULL;
}

int combineAlternating(ListNode **ptrHead, ListNode *head1, ListNode *head2)
{
    /* Write your program code here */
    int i = 0;

    if (head1 == NULL && head2 == NULL)
        return 0;

    while (head1 != NULL || head2 != NULL)
    {
        if (head1 != NULL)
        {
            insertNode(ptrHead, i, head1->item);
            i++;
            head1 = head1->next;
        }

        if (head2 != NULL)
        {
            insertNode(ptrHead, i, head2->item);
            i++;
            head2 = head2->next;
        }
    }

    return 1;
}
