// CX1007 Data Structures
// Week 10 P4

#include <stdio.h>
#include <stdlib.h>

struct _dbllistnode
{
    int item;
    struct _dbllistnode *pre;
    struct _dbllistnode *next;
};
typedef struct _dbllistnode DblListNode;

// DblListNode *findDblListNode(DblListNode *cur, int index);
void printDblList(DblListNode *cur);
void deleteList(DblListNode **ptrHead);

int insertDbl(DblListNode **ptrHead, int index, int value);

int main()
{
    int item, index;
    int size=0;
    DblListNode* head=NULL;

    printf("Enter a number and an index for inserting a node, terminated by invalid input: \n");
    while(scanf("%d %d",&item,&index)==2)
    {
        if(insertDbl(&head,index,item)) size++;
        else printf("Invalid Insertion!\n");
        printDblList(head);
        printf("Enter a number and an index for inserting a node, terminated by invalid input: \n");
    }

    printf("\nFinal List has %d elements:\n",size);
    printDblList(head);

    if(head!=NULL)
        deleteList(&head);
    return 0;
}

//Same as Singly Linked List's findNode()
DblListNode *findDblListNode(DblListNode *cur, int index)
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

//same as singly linked list's print function
void printDblList(DblListNode *cur)
{
    printf("Current List: ");
    while (cur != NULL)
    {
        printf("%d ", cur->item);
        cur = cur->next;
    }
    printf("\n");
}

void deleteList(DblListNode **ptrHead)
{
    DblListNode *cur = *ptrHead;
    DblListNode *temp;
    while (cur!= NULL)
    {
        temp=cur->next;
        free(cur);
        cur=temp;
    }
    *ptrHead=NULL;
}

int insertDbl(DblListNode **ptrHead, int index, int value)
{
    /* Write your program code here.*/
    DblListNode *temp = NULL, *pre = NULL;
    temp = *ptrHead;

    //index 0 or empty list
    if (index == 0)
    {
        temp = malloc(sizeof(DblListNode));
        temp->item = value;
        temp->next = *ptrHead;
        temp->pre = NULL;

        if (*ptrHead != NULL)
            (*ptrHead)->pre = temp;

        *ptrHead = temp;
        return 1;
    }

    else if ((pre = findDblListNode(*ptrHead, index-1)) != NULL)
    {
        temp = malloc(sizeof(DblListNode));
        temp->item = value;
        temp->next = pre->next;
        temp->pre = pre;

        if (pre->next != NULL)
        {
            temp->next->pre = temp;
        }

        pre->next = temp;

        return 1;
    }

    return 0;
}
