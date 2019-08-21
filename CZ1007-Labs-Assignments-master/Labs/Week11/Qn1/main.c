//CE1007/CZ1007 Data Structures
// Week 11 Lab Tutorial - Stacks and Queues
// Question 1

#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
    int item;
    struct _listnode *next;
} ListNode;
typedef ListNode StackNode;

typedef struct _linkedlist
{
    int size;
    ListNode *head;
} LinkedList;
typedef LinkedList Stack;

//simply reuse linked list's print function
void printList(ListNode *cur);

void push(Stack *sPtr, int item);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);

void removeUntil(Stack *sPtr, int value);

int main()
{
    Stack s;
    s.head=NULL;
    s.size=0;
    int item;

    printf("Enter a list of numbers for a stack, terminated by any non-digit character: \n");
    while(scanf("%d",&item))
        push(&s, item);
    scanf("%*s");
    printf("\nBefore removeUntil() is called:\n");
    printList((ListNode *)s.head);

    printf("Enter an integer value for removeUntil()\n");
    scanf("%d",&item);
    removeUntil(&s,item);
    printf("\nAfter removeUntil() was called:\n");
    printList((ListNode *)s.head);

    //free dynamic memory is omitted here!
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

void push(Stack *sPtr, int item)
{
    StackNode *newNode;
    newNode= malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr)
{
    if(sPtr==NULL || sPtr->head==NULL)
    {
        return 0;
    }
    else
    {
        StackNode *temp = sPtr->head;
        sPtr->head = sPtr->head->next;
        free(temp);
        sPtr->size--;
        return 1;
    }
}

int peek(Stack s)
{
    return s.head->item;
}

int isEmptyStack(Stack s)
{
    if(s.size==0) return 1;
    else return 0;
}

void removeUntil(Stack *sPtr, int value)
{
    /*Write your program code here*/
    while (!isEmptyStack(*sPtr))
    {
        if (peek(*sPtr) == value)
            break;
        else
            pop(sPtr);
    }
}
