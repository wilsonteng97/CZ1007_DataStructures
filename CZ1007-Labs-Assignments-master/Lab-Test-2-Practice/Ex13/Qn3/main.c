//CE1007/CZ1007 Data Structures
// Week 13 Lab Tutorial - Binary Search Tree
// Question 3

#include <stdio.h>
#include <stdlib.h>

#define MAXSPACE 8

typedef struct _btnode
{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

BTNode* insertBSTNode(BTNode* cur, int item);
BTNode* insertBTNode(BTNode* cur, int item);

void printBTNode(BTNode *root, int space);
void deleteTree(BTNode *root);

int isBST(BTNode *root);

int main()
{
    BTNode* rootBST=NULL;
    BTNode* rootBT=NULL;
    int item;

    printf("Enter a list of numbers for a Binary Tree, terminated by any non-digit character: \n");
    while(scanf("%d",&item))
    {
        rootBST = insertBSTNode(rootBST, item);
        rootBT = insertBTNode(rootBT,item);
    }
    scanf("%*s");

    printf("The binary tree is %s:\n",isBST(rootBST)?"a BST": "not a BST");
    printBTNode(rootBST,0);
    printf("The binary tree is %s:\n",isBST(rootBT)?"a BST": "not a BST");
    printBTNode(rootBT,0);

    deleteTree(rootBST);
    rootBST=NULL;
    deleteTree(rootBT);
    rootBT=NULL;

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

BTNode* insertBSTNode(BTNode* cur, int item)
{
    if (cur == NULL)
    {
        BTNode* node = (BTNode*) malloc(sizeof(BTNode));
        node->item = item;
        node->left = node->right = NULL;
        return node;
    }
    if (item < cur->item)
        cur->left  = insertBSTNode (cur->left, item);
    else if (item > cur->item)
        cur->right = insertBSTNode (cur->right, item);
    else
        printf("Duplicated Item: %d\n",item);

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

int isBST(BTNode *root)
{
    /* Write your program code here */
    return isBSTX(root, NULL, NULL);
}

int isBSTX(BTNode *root, BTNode *left, BTNode *right)
{
    if (root == NULL)
        return 1;

    if (left != NULL && root->item <= left->item)
        return 0;

    if(right != NULL && root->item >= right->item)
        return 0;

    return isBSTX(root->left, left, root) && isBSTX(root->right, root, right);
}
