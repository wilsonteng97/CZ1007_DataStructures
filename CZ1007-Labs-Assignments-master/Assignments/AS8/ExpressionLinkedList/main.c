#include <stdio.h>
#include <stdlib.h>
//#include "AS8Q5.h" //Please comment it in your codeblock after linking the library file

#ifndef _NODE_
#define _NODE_
typedef struct _node
{
    int item;
    struct _node *next;
} numNode;

typedef struct _nodeOp
{
    char item;
    struct _nodeOp *next;
} opNode;

typedef struct _linkedlistEx
{
    numNode *numHead;
    opNode *opHead;
} LinkedListExp;
#endif
void expressionLL(char* exp,LinkedListExp* llE);

int main()
{
    LinkedListExp* llE = malloc(sizeof(LinkedListExp));
    expressionLL("145+158*(25+1574*174/2)-32+1050", llE);
    return 0;
}

void expressionLL(char* exp,LinkedListExp* llE)
{
    /* add your code here */

    int i = 0;
    char *p = exp, numStr[20];
    struct _nodeOp *opTemp = NULL;
    struct _node *numTemp = NULL;
    opTemp = malloc(sizeof(struct _nodeOp));
    numTemp = malloc(sizeof(struct _node));

    while (*p != '\0')
    {
        if (isdigit(*p))
        {
            *(numStr + i) = *p;
            i++;
        }
        else
        {
            if (llE->numHead == NULL && (i != 0))
            {
                llE->numHead = malloc(sizeof(struct _node));
                llE->numHead->item = atoi(numStr);
                llE->numHead->next = NULL;
                numTemp = llE->numHead;
            }
            else if (i != 0)
            {
                struct _node *temp = malloc(sizeof(numNode));
                temp->item = atoi(numStr);
                temp->next = NULL;
                numTemp->next = temp;
                numTemp = temp;
            }

            if (llE->opHead == NULL)
            {
                llE->opHead = malloc(sizeof(struct _nodeOp));
                llE->opHead->item = *p;
                llE->opHead->next = NULL;
                opTemp = llE->opHead;
            }
            else
            {
                struct _nodeOp *temp = malloc(sizeof(opNode));
                temp->item = *p;
                temp->next = NULL;
                opTemp->next = temp;
                opTemp = temp;
            }

            i--;

            while (i >= 0)
            {
                *(numStr + i) = 0;
                i--;
            }

            i = 0;
        }

        if (*(p+1) == '\0')
        {
            if (llE->numHead == NULL && (i != 0))
            {
                llE->numHead = malloc(sizeof(struct _node));
                llE->numHead->item = atoi(numStr);
                llE->numHead->next = NULL;
                numTemp = llE->numHead;
            }
            else if (i != 0)
            {
                struct _node *temp = malloc(sizeof(numNode));
                temp->item = atoi(numStr);
                temp->next = NULL;
                numTemp->next = temp;
                numTemp = temp;
            }
        }

        p++;
    }
}
