/////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
Purpose: Implementing the required functions for Question 4 */
//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
//#include "AS9_Q4.h"  //Comment it and include library file when you work on code::blocks
//////////////////////////////////   Stack  & Queue /////////////////////////////////
#ifndef _AS9_Q4_
#define _AS9_Q4_
typedef struct _listnode
{
    int item;
    struct _listnode *next;
} ListNode;

typedef ListNode QueueNode;
typedef ListNode StackNode;

typedef struct _queue
{
    int size;
    QueueNode *head;
    QueueNode *tail;
} Queue;

typedef struct _stack
{
    int size;
    ListNode *head;
} Stack;
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////

void reverse(Queue *qPtr);

///////////////////////////////////////////////////////////////////////////////////////////////////

void push(Stack *sPtr, int item);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void removeAllItemsFromStack(Stack *sPtr);

void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void removeAllItemsFromQueue(Queue *qPtr);

int test_main(void (*reverse)(Queue *),void (*removeAllItemsFromQueue)(Queue *));
///////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    test_main(reverse,removeAllItemsFromQueue);
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

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

void enqueue(Queue *qPtr, int item)
{
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    if(newNode==NULL) exit(0);

    newNode->item = item;
    newNode->next = NULL;

    if(isEmptyQueue(*qPtr))
        qPtr->head=newNode;
    else
        qPtr->tail->next = newNode;

    qPtr->tail = newNode;
    qPtr->size++;
}

int dequeue(Queue *qPtr)
{
    if(qPtr==NULL || qPtr->head==NULL)  //Queue is empty or NULL pointer
    {
        return 0;
    }
    else
    {
        QueueNode *temp = qPtr->head;
        qPtr->head = qPtr->head->next;
        if(qPtr->head == NULL) //Queue is emptied
            qPtr->tail = NULL;

        free(temp);
        qPtr->size--;
        return 1;
    }
}

int getFront(Queue q)
{
    return q.head->item;
}

int isEmptyQueue(Queue q)
{
    if(q.size==0) return 1;
    else return 0;
}

void removeAllItemsFromQueue(Queue *qPtr)
{
    while(dequeue(qPtr));
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void reverse(Queue *qPtr)
{
    /* add your code here */
    Stack *tempStack = malloc(sizeof(Stack));

    while (!isEmptyQueue(*qPtr))
    {
        push(tempStack, getFront(*qPtr));
        dequeue(qPtr);
    }

    while (!isEmptyStack(*tempStack))
    {
        enqueue(qPtr, peek(*tempStack));
        pop(tempStack);
    }

    free(tempStack);
}
