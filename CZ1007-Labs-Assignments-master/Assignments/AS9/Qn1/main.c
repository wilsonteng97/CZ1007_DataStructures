/////////////////////////////////////////////////////////////////////////////////



/* CE1007/CZ1007 Data Structures

Purpose: Implementing the required functions for Question 1 */



//////////////////////////////////////////////////////////////////////////////////



#include <stdio.h>

#include <stdlib.h>

//#include "AS9_Q1.h"  //Comment it and include library filewhen you work on code::blocks

//////////////////////////////////////////////////////////////////////////////////

#ifndef _AS9_Q1_

#define _AS9_Q1_

typedef struct _listnode

{

    int item;

    struct _listnode *next;

} ListNode;	// You should not change the definition of ListNode



typedef ListNode QueueNode;



typedef struct _linkedlist

{

    int size;

    ListNode *head;

} LinkedList;	// You should not change the definition of LinkedList



typedef struct _queue
{

    int size;

    QueueNode *head;

    QueueNode *tail;

} Queue;

#endif

///////////////////////// function prototypes ////////////////////////////////////



// You should not change the prototypes of these functions

void createQueueFromLinkedList(LinkedList ll, Queue *qPtr);

void removeOddValues(Queue *qPtr);



void enqueue(Queue *qPtr, int item);

int dequeue(Queue *qPtr);

int getFront(Queue q);

int isEmptyQueue(Queue q);

void removeAllItemsFromQueue(Queue *qPtr);



//////////////////////////// main() //////////////////////////////////////////////

int test_main(void (*createQueueFromLinkedList)(LinkedList, Queue *),void (*removeOddValue)(Queue *),void (*removeAllItemsFromQueue)(Queue *));

int main()

{

    test_main(createQueueFromLinkedList,removeOddValues,removeAllItemsFromQueue);

    return 0;

}



//////////////////////////////////////////////////////////////////////////////////



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

//////////////////////////////////////////////////////////////////////////////////



void createQueueFromLinkedList(LinkedList ll, Queue *qPtr)
{
    /* add your code here */
    int i = 0;
    ListNode *temp;

    if (!isEmptyQueue(*qPtr))
        removeAllItemsFromQueue(qPtr);

    temp = ll.head;

    for (i=0; i < ll.size; i++)
    {
        enqueue(qPtr, temp->item);
        temp = temp->next;
    }
}



void removeOddValues(Queue *qPtr)
{
    /* add your code here */
    int i, item, size;
    size = qPtr->size;

    for (i=0; i < size; i++)
    {
        item = getFront(*qPtr);

        dequeue(qPtr);

        if (item % 2 == 0)
            enqueue(qPtr, item);
    }
}
