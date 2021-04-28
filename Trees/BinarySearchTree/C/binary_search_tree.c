#include <stdlib.h>
#include <stdio.h>

/* Tree Node */
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* new_Node(int data) // Node Constructor
{
    Node *n = (Node*) malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

/* Binary Search Tree */
typedef struct BST
{
    Node *root;
} BST;

BST* new_BST()  // BST Constructor
{
    BST* bst = (BST*) malloc(sizeof(BST));
    bst->root = NULL;
    return bst;
}

/* BST OPERATION PROTOTYPES */
void insert_iter(BST* root, int item);
void insert_recurse(BST *bst, int item);
Node* insert_helper(Node *n, int item);
int search_iter(BST* bst, int target);
int search_recurse(BST* bst, int target);
int search_helper(Node* n, int target);
void inorder_recurse(BST* bst);
void inorder_helper(Node* n);

void insert_iter(BST* bst, int item)
{
    Node* new_node = new_Node(item);
    Node* p = bst->root;
    if (p == NULL)
    {
        bst->root = new_node;
    }
    else
    {
        while (1)
        {
            if (p->data > new_node->data)
            {
                if (p->left == NULL)
                {
                    p->left = new_node;
                    break;
                }
                p = p->left;
            }
            else
            {
                if (p->right == NULL)
                {
                    p->right = new_node;
                    break;
                }
                p = p->right;
            }
        }
    }
}

void insert_recurse(BST *bst, int item)
{
    bst->root = insert_helper(bst->root, item);
}

Node* insert_helper(Node *n, int item)
{
    if (n == NULL) 
        return new_Node(item);
    if (n->data < item) 
        n->right = insert_helper(n->right, item);
    if (n->data > item) 
        n->left = insert_helper(n->left, item);
    return n;
}

int search_iter(BST* bst, int target)
{
    Node *n = bst->root;
    while (n)
    {
        if (n->data == target)
            return 1;
        else if (n->data < target)
            n = n->right;
        else
            n = n->left;
    }
    return 0;
}

int search_recurse(BST* bst, int target)
{
    return search_helper(bst->root, target);
}

int search_helper(Node* n, int target)
{
    if (n == NULL) 
        return 0;
    else if (n->data == target) 
        return 1;
    else if (n->data > target) 
        return search_helper(n->left, target);
    else 
        return search_helper(n->right, target);
}

void inorder_recurse(BST *bst)
{
    inorder_helper(bst->root);
}

void inorder_helper(Node* n)
{
    if (n->left != NULL)
        inorder_helper(n->left);
    printf("%d ", n->data);
    if (n->right != NULL)
        inorder_helper(n->right);
}

int main()
{
    int arr[] = {5, 3, 9, 2, 4, 6, 10};
    BST* bst = new_BST();
    for (int i = 0; i < 7; i++)
        insert_recurse(bst, arr[i]);
    printf("Inorder: ");
    inorder_recurse(bst);
    printf("\n");
    int x;
    while (1)
    {
        printf("Enter an item to search for: ");
        scanf("%d", &x);
        int res = search_recurse(bst, x);
        if (res == 1)
            printf("%d is in the tree.\n", x);
        else
            printf("%d is not in the tree.\n", x);
    }
}