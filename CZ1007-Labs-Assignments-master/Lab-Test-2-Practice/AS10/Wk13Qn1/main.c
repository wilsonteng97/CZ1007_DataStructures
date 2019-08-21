//CE1007/CZ1007 Data Structures
// Week 13 Lab Tutorial - Binary Search Tree
// Question 1

#include <stdio.h>
#include <stdlib.h>

#define MAXSPACE 8

typedef struct _btnode
{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void insertBTNode(BTNode** cur, int item);
void printBTNode(BTNode *root, int space);
void deleteTree(BTNode *root);

int main()
{
    BTNode* root=NULL;
    int item;

    printf("Enter a list of numbers for a Binary Tree, terminated by any non-digit character: \n");
    while(scanf("%d",&item))
        insertBTNode(&root, item);
    scanf("%*s");

    printf("The Binary Search Tree:\n");
    printBTNode(root,0);

    deleteTree(root);
    root=NULL;
    return 0;
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

void insertBTNode(BTNode** cur, int item)
{
    /* Write your program code here */
    BTNode *temp, *curr;
    curr = *cur;

    temp = malloc(sizeof(BTNode));
    temp->item = item;
    temp->left = NULL;
    temp->right = NULL;

    if (*cur == NULL)
    {
        *cur = temp;
        return;
    }

    while (curr != NULL)
    {
        if (curr->item == item)
        {
            printf("Duplicated Item: %d\n", item);
            return;
        }

        if (item < curr->item)
            if (curr->left == NULL)
            {
                curr->left = temp;
                break;
            }
            else
                curr = curr->left;
        else
            if (curr->right == NULL)
            {
                curr->right = temp;
                break;
            }
            else
                curr = curr->right;
    }
}
