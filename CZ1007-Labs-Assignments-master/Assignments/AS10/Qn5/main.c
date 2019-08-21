#include <stdio.h>
#include <stdlib.h>

//#include "AS10Q5.h"  //Please comment this line in Code::Blocks. The header is not provided. It is used in APAS only.

#ifndef _NODE_
#define _NODE_
typedef struct _btnode
{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;   // You should not change the definition of BTNode

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

void addLeaves(BTNode **node, numNode **num);

void createExpTree(BTNode** root,LinkedListExp myexp);
void deleteTree(BTNode **root);

void printTree(BTNode *node);
void printTreePostfix(BTNode *node);

double computeTree(BTNode *node);

int main()
{
    test_main(createExpTree,deleteTree,printTree,printTreePostfix,computeTree);
    return 0;
}

void deleteTree(BTNode **root)
{
    BTNode* temp;
    if(*root !=NULL)
    {
        temp = (*root)->right;
        deleteTree(&((*root)->left));
        free(*root);
        *root = NULL;
        deleteTree(&temp);
    }
}

void createExpTree(BTNode** root,LinkedListExp myexp)
{
    /* add your code here */
    BTNode *temp, *newNode;
    numNode *num;
    opNode *op;

    deleteTree(&*root);

    num = myexp.numHead;
    op = myexp.opHead;
    temp = *root;

    //Empty input
    if (num == NULL && op == NULL)
        return;

    while (op != NULL)
    {
        temp = *root;

        newNode = malloc(sizeof(BTNode));
        newNode->item = op->item;
        newNode->left = NULL;
        newNode->right = NULL;

        //First operator
        if (temp == NULL)
        {
            temp = newNode;
            *root = temp;
        }
        //High precedence
        else if ((op->item == '*' || op->item == '/') && (temp->item == '+' || temp->item == '-'))
        {
            if (temp->right == NULL)
            {
                temp->right = newNode;
            }
            else
            {
                newNode->left = temp->right;
                temp->right = newNode;
            }
        }
        //Low precedence
        else
        {
            newNode->left = temp;
            newNode->right = NULL;
            temp = newNode;
            *root = temp;
        }

        op = op->next;
    }

    addLeaves(&*root, &num);
}

void addLeaves(BTNode **node, numNode **num)
{
    /* add your code here */
    if (num == NULL)
        return;

    if (*node == NULL)
    {
        *node = malloc(sizeof(BTNode));
        (*node)->item = (*num)->item;
        (*node)->left = NULL;
        (*node)->right = NULL;
        *num = (*num)->next;
    }
    else
    {
        addLeaves(&((*node)->left), &(*num));
        addLeaves(&((*node)->right), &(*num));
    }
}


void printTree(BTNode *node)
{
    /* add your code here */
    if (node != NULL)
    {
        printTree(node->left);
        if (node->left == NULL && node->right == NULL)
            printf("%d ", node->item);
        else
            printf("%c ", node->item);
        printTree(node->right);
    }
}


void printTreePostfix(BTNode *node)
{
    //add your code here
    if (node != NULL)
    {
        printTreePostfix(node->left);
        printTreePostfix(node->right);
        if (node->left == NULL && node->right == NULL)
            printf("%d ", node->item);
        else
            printf("%c ", node->item);
    }
}

double computeTree(BTNode *node)
{
    /* add your code here */
    double left, right;

    if (node == NULL)
        return 0;

    if (node->left == NULL && node->right == NULL)
        return node->item;

    left = computeTree(node->left);
    right = computeTree(node->right);

    switch(node->item)
    {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    }

    return left / right;
}
