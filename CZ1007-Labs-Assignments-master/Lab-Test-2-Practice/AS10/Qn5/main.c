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

void createExpTree(BTNode** root,LinkedListExp myexp);
void deleteTree(BTNode **root);
void addNumbers(BTNode **node, numNode **num);

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
    opNode *op;
    numNode *num;
    BTNode *newNode;
    op = myexp.opHead;
    num = myexp.numHead;

    deleteTree(root);

    if (op == NULL && num == NULL)
        return;

    while (op != NULL)
    {
        newNode = malloc(sizeof(BTNode));
        newNode->item = op->item;
        newNode->left = NULL;
        newNode->right = NULL;
        op = op->next;

        if (*root == NULL)
            *root = newNode;
        else
        {
            if (newNode->item == '+' || newNode->item == '-')
            {
                newNode->left = *root;
                *root = newNode;
            }
            else
            {
                if ((*root)->right == NULL)
                    (*root)->right = newNode;
                else
                {
                    newNode->left = (*root)->right;
                    (*root)->right = newNode;
                }
            }
        }
    }

    addNumbers(&*root, &num);
}

void addNumbers(BTNode **node, numNode **num)
{
    if (*num == NULL)
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
        addNumbers(&((*node)->left), &*num);
        addNumbers(&((*node)->right), &*num);
    }
}

void printTree(BTNode *node)
{
    /* add your code here */
    if (node == NULL)
        return;

        printTree(node->left);
        if (node->left == NULL && node->right == NULL)
            printf("%d ", node->item);
        else
            printf("%c ", node->item);
        printTree(node->right);

}


void printTreePostfix(BTNode *node)
{
    /* add your code here */
    if (node == NULL)
        return;

    printTreePostfix(node->left);
    printTreePostfix(node->right);
    if (node->left == NULL && node->right == NULL)
        printf("%d ", node->item);
    else
        printf("%c ", node->item);
}

double computeTree(BTNode *node){
    if(node->left == NULL && node->right == NULL) return node->item;

    switch((char)(node->item)){
       case '*':
         return (double) computeTree(node->left)*computeTree(node->right);
       case '/':
         return (double) computeTree(node->left)/computeTree(node->right);
       case '+':
         return (double) computeTree(node->left)+computeTree(node->right);
       case '-':
         return (double) computeTree(node->left)-computeTree(node->right);
    }
    return 0.0;
}
