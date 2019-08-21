//CE1007/CZ1007 Data Structures
// Week 12 Lab Tutorial - Binary Tree
// Question 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSPACE 4

typedef struct _btnode
{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

BTNode* insertBTNode(BTNode* cur, int item);
void printBTNode(BTNode *root, int space);
void deleteTree(BTNode *root);

void mirrorTree(BTNode *node);

int main()
{
    BTNode* root=NULL;
    int item;

    printf("Enter a list of numbers for a Binary Tree, terminated by any non-digit character: \n");
    while(scanf("%d",&item))
        root = insertBTNode(root, item);
    scanf("%*s");

    printf("Original Tree\n");
    printBTNode(root,0);
    printf("---------------------------------------------------------------\n");
    mirrorTree(root);
    printBTNode(root,0);
    printf("Mirrored Tree\n");

    deleteTree(root);
    root=NULL;

    return 0;
}

BTNode* insertBTNode(BTNode* cur, int item)
{
    if (cur == NULL)
    {
        BTNode* node = (BTNode*) malloc(sizeof(BTNode));
        node->item = item;
        node->left = node->right = NULL;
        return node;
    }
    if (rand()%2)
        cur->left  = insertBTNode (cur->left, item);
    else
        cur->right = insertBTNode (cur->right, item);

    return cur;
}
void printBTNode(BTNode *root,int space)
{
    // Base case
    if (root == NULL)
        return;
    // Increase distance between levels
    space += MAXSPACE;

    // "Reversed" inorder tree traversal
    printBTNode(root->right, space);

    printf("\n");
    for (int i = MAXSPACE; i < space; i++)
        printf(" ");
    printf("%d\n", root->item);

    printBTNode(root->left, space);
}

void deleteTree(BTNode *root)
{
    BTNode* temp;
    if(root !=NULL)
    {
        temp = root->right;
        deleteTree(root->left);
        free(root);
        deleteTree(temp);
    }
}

void mirrorTree(BTNode *node)
{
    /* Write your program code here */
    BTNode *tempChild;

    if (node != NULL)
    {
        tempChild = node->right;
        node->right = node->left;
        node->left = tempChild;

        mirrorTree(node->left);
        mirrorTree(node->right);
    }
}
