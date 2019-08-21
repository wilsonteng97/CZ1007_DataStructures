/////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
Purpose: Implementing the required functions for Question 2 */
//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
//#include "AS9_Q2.h"  //Comment it and include library filewhen you work on code::blocks
//////////////////////////////////////////////////////////////////////////////////
#ifndef _AS9_Q2_
#define _AS9_Q2_
typedef struct _listnode
{
    int item;
    struct _listnode *next;
} ListNode;	// You should not change the definition of ListNode

typedef ListNode StackNode;

typedef struct _linkedlist
{
    int size;
    ListNode *head;
} LinkedList;	// You should not change the definition of LinkedList

typedef LinkedList Stack;
#endif
///////////////////////// function prototypes ////////////////////////////////////

// You should not change the prototypes of these functions
void createStackFromLinkedList(LinkedList ll, Stack *sPtr);
void removeEvenValues(Stack *sPtr);

void push(Stack *sPtr, int item);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void removeAllItemsFromStack(Stack *sPtr);

//////////////////////////// main() //////////////////////////////////////////////
int test_main(void (*createStackFromLinkedList)(LinkedList, Stack *),void (*removeEvenValues)(Stack *),void (*removeAllItemsFromStack)(Stack *));
int main()
{
    test_main(createStackFromLinkedList,removeEvenValues,removeAllItemsFromStack);
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////

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

int isEmptyStack(Stack s)
{
    if(s.size==0) return 1;
    else return 0;
}

int peek(Stack s)
{
    return s.head->item;
}

void removeAllItemsFromStack(Stack *sPtr)
{
    while(pop(sPtr));
}

//////////////////////////////////////////////////////////////////////////////////

void createStackFromLinkedList(LinkedList ll, Stack *sPtr)
{
    /* add your code here */
    ListNode *temp;

    temp = ll.head;

    if(!(isEmptyStack(*sPtr)))
        removeAllItemsFromStack(sPtr);
    else
    {
        while (temp != NULL)
        {
            push(sPtr, temp->item);
            temp = temp->next;
        }
    }
}

void removeEvenValues(Stack *sPtr)
{
    /* add your code here */
    int item = 0;
    Stack *tempStack = malloc(sizeof(Stack));
    tempStack->size = 0;
    tempStack->head = NULL;

    if (sPtr == NULL)
        return;

    while (!isEmptyStack(*sPtr))
    {
        item = peek(*sPtr);
        pop(sPtr);

        if (abs(item) % 2 == 1)
            push(tempStack, item);
    }

    while (!isEmptyStack(*tempStack))
    {
        item = peek(*tempStack);
        push(sPtr, item);
        pop(tempStack);
    }
}
