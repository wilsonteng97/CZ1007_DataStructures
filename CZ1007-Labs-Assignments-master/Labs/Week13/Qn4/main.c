//CE1007/CZ1007 Data Structures
// Week 13 Lab Tutorial - Binary Search Tree
// Question 4

#include <stdio.h>
#include <stdlib.h>

#define MAXSPACE 8

typedef struct _btnode
{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

BTNode* findMin(BTNode *node);
BTNode* insertBSTNode(BTNode* cur, int item);
void printBTNode(BTNode *root, int space);
void deleteTree(BTNode *root);
int removeBSTNode(BTNode **nodePtr, int item);

int main()
{
    BTNode* root=NULL;
    int item;

    printf("Enter a list of numbers for a Binary Tree, terminated by any non-digit character: \n");
    while(scanf("%d",&item))
        root = insertBSTNode(root, item);
    scanf("%*s");

    printf("The Binary Search Tree:\n");
    printBTNode(root,0);

    printf("Enter an integer to be removed from the tree:\n");
    scanf("%d",&item);

    if(removeBSTNode(&root,item))
        printf("%d was removed\n",item);

    else
        printf("%d is not in the tree.\n",item);

    printf("The Binary Search Tree:\n");
    printBTNode(root,0);

    deleteTree(root);
    root=NULL;
    return 0;
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

int removeBSTNode(BTNode **nodePtr, int item)
{
    /* Write your program code here. */
    BTNode *temp = NULL;

    if (*nodePtr == NULL)
        return 0;

    //Item in left sub tree
    if (item < (*nodePtr)->item)
        removeBSTNode(&((*nodePtr)->left), item);
    //Item in right sub tree
    else
        removeBSTNode(&((*nodePtr)->right), item);

    //Case 1: No Children
    if ((*nodePtr)->left == NULL && (*nodePtr)->right == NULL)
    {
        free(*nodePtr);
        *nodePtr = NULL;
        return 1;
    }

    //Case 2: One left child
    if ((*nodePtr)->right == NULL)
    {
        temp = *nodePtr;
        *nodePtr = (*nodePtr)->left;
        free(temp);
        return 1;
    }

    //Case 3: One right child
    if ((*nodePtr)->left == NULL)
    {
        temp = *nodePtr;
        *nodePtr = (*nodePtr)->right;
        free(temp);
        return 1;
    }

    //Case 4: Two children
    if ((*nodePtr)->right != NULL && (*nodePtr)->left != NULL)
    {
        temp = findMin((*nodePtr)->right);
        (*nodePtr)->item = temp->item;

        return removeBSTNode(&((*nodePtr)->right), temp->item);
    }
}

BTNode *findMin(BTNode *node)
{
   if (node->left != NULL)
      return findMin(node->left);

   return node;
}
