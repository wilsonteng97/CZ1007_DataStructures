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

//void expressionLL(char* exp,LinkedListExp* llE)
//{
//    /* add your code here */
//    int var = 0;
//    numNode *num = llE->numHead, *numToAdd;
//    opNode *op = llE->opHead, *opToAdd;
//
//    while (*exp != '\0')
//    {
//        if (*exp == ' ')
//        {
//            //Do nothing
//        }
//        else if (*exp == '+' || *exp == '-' || *exp == '*' || *exp == '/' || *exp == '(' || *exp == ')')
//        {
//            opToAdd = malloc(sizeof(opNode));
//            opToAdd->item = *exp;
//            opToAdd->next = NULL;
//
//            if (llE->opHead == NULL)
//            {
//                llE->opHead = opToAdd;
//                op = llE->opHead;
//            }
//            else
//            {
//                op->next = opToAdd;
//                op = op->next;
//            }
//
//            if (var != 0)
//            {
//                numToAdd = malloc(sizeof(numNode));
//                numToAdd->item = var;
//                numToAdd->next = NULL;
//
//                if (llE->numHead == NULL)
//                {
//                    llE->numHead = numToAdd;
//                    num = llE->numHead;
//                }
//                else
//                {
//                    num->next = numToAdd;
//                    num = num->next;
//                }
//
//                var = 0;
//            }
//        }
//        else
//        {
//            if (var == 0)
//                var = *exp - '0';
//            else
//            {
//                var *= 10;
//                var += (*exp - '0');
//            }
//        }
//        printf("%d\n", var);
//
//        exp++;
//    }
//
//    opToAdd = malloc(sizeof(opNode));
//    opToAdd->item = *exp;
//    opToAdd->next = NULL;
//
//    if (llE->opHead == NULL)
//    {
//        llE->opHead = opToAdd;
//        op = llE->opHead;
//    }
//    else
//    {
//        op->next = opToAdd;
//        op = op->next;
//    }
//
//    if (var != 0)
//    {
//        numToAdd = malloc(sizeof(numNode));
//        numToAdd->item = var;
//        numToAdd->next = NULL;
//
//        if (llE->numHead == NULL)
//        {
//            llE->numHead = numToAdd;
//            num = llE->numHead;
//        }
//        else
//        {
//            num->next = numToAdd;
//            num = num->next;
//        }
//
//        var = 0;
//    }
//}

void expressionLL(char* exp,LinkedListExp* llE)
{
    /* add your code here */
    int var = 0;
    numNode *num = llE->numHead, *numToAdd;
    opNode *op = llE->opHead, *opToAdd;

    while (*exp != '\0')
    {
        if (*exp == ' ')
        {
            exp++;
        }
        else if (*exp == '+' || *exp == '-' || *exp == '*' || *exp == '/' || *exp == '(' || *exp == ')')
        {
            opToAdd = malloc(sizeof(opNode));
            opToAdd->item = *exp;
            opToAdd->next = NULL;

            if (llE->opHead == NULL)
            {
                llE->opHead = opToAdd;
                op = llE->opHead;
            }
            else
            {
                op->next = opToAdd;
                op = op->next;
            }

            exp++;
        }
        else
        {
            numToAdd = malloc(sizeof(numNode));
            numToAdd->item = atoi(exp);
            numToAdd->next = NULL;

            if (llE->numHead == NULL)
            {
                llE->numHead = numToAdd;
                num = llE->numHead;
            }
            else
            {
                num->next = numToAdd;
                num = num->next;
            }

            while (!(*exp == '+' || *exp == '-' || *exp == '*' || *exp == '/' || *exp == '(' || *exp == ')' || *exp == '\0'))
                exp++;
        }
    }
}
