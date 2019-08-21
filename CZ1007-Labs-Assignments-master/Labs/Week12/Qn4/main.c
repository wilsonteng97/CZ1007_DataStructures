#include <stdio.h>
#include <stdlib.h>

#define MAXSPACE 8

typedef struct _btnode
{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

BTNode* insertBTNode(BTNode* cur, int item);
void printBTNode(BTNode *root, int space);
void deleteTree(BTNode *root);

int hasGreatGrandchild(BTNode *node);

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

    printf("The node(s) with great grandchild:\n");
    hasGreatGrandchild(root);
    printf("\n");

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

int hasGreatGrandchild(BTNode *node)
{
    /* Write your program code here. */
    int count = 0, l = 0, r = 0;

    if (node == NULL)
        return 0;

    l = hasGreatGrandchild(node->left);
    //printf("left %d\n", l);
    r = hasGreatGrandchild(node->right);
    //printf("right %d\n", r);

    if (r > 2 || l > 2)
    {
        printf("%d ", node->item);
    }

    return (l > r) ? (l + 1) : (r + 1);
}
