// CX1007 Data Structures
// Week 10 P1

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

int moveMaxToFront(ListNode **ptrHead);

int main()
{
    ListNode *head=NULL;
    int size =0;
    int item;

    printf("Enter a list of numbers, terminated by any non-digit character: \n");
    while(scanf("%d",&item))
        if(insertNode(&head,size, item)) size++;
    scanf("%*s");

    printf("\nBefore moveMaxToFront() is called:\n");
    printList(head);

    int maxIndex = moveMaxToFront(&head);

    printf("\nAfter moveMaxToFront() was called:\n");
    printf("The original index of the node with the largest value: %d.\n",maxIndex);
    printList(head);

    if(head!=NULL)
        deleteList(&head);

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

int moveMaxToFront(ListNode **ptrHead)
{
    /* Write your program code here. */
    ListNode *temp = NULL, *pre = NULL;
    int max, index = 0, i = 0;

    //Empty List
    if (*ptrHead == NULL)
        return -1;

    //Only 1 item
    if((*ptrHead)->next == NULL)
        return 0;

    temp = *ptrHead;
    max = temp->item;

    while (temp != NULL)
    {
        if (max < temp->item)
        {
            max = temp->item;
            index = i;
        }

        i++;
        temp = temp->next;
    }

    if((pre = findNode(*ptrHead, index-1)) == NULL)
        return -1;

    temp = pre->next;
    pre->next = temp->next;
    temp->next = *ptrHead;
    *ptrHead = temp;
    return index;
}
