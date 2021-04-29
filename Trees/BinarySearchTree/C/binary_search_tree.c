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
void delete_recurse(BST* bst, int target);
Node* delete_recurse_helper(Node* n, int target);
int height(Node* root);
Node* get_successor(Node *n);
Node* get_predecessor(Node *n);
void create_BST_from_preorder();

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

void delete_recurse(BST* bst, int target)
{
    bst->root = delete_recurse_helper(bst->root, target);
}

Node* delete_recurse_helper(Node* n, int target)
{
    if (n == NULL)
        return NULL;
    else if (n->left == NULL && n->right == NULL && n->data == target)
    {
        free(n);
        return NULL;
    }
    else if (n->data > target)
        n->left = delete_recurse_helper(n->left, target);
    else if (n->data < target)
        n->right = delete_recurse_helper(n->right, target);
    else
    {
        if (height(n->left) > height(n->right))
        {
            Node* t = get_predecessor(n->left);
            n->data = t->data;
            n->left = delete_recurse_helper(n->left, t->data);
        }
        else
        {
            Node* t = get_successor(n->right);
            n->data = t->data;
            n->right = delete_recurse_helper(n->right, t->data);
        }
    }
    return n;
}

Node* get_predecessor(Node *n)
{
    if (n->right)
        return get_predecessor(n->right);
    return n;
}

Node* get_successor(Node *n)
{
    if (n->left)
        return get_successor(n->left);
    return n;
}

int height(Node* root)
{
    if (root == NULL)
        return -1;
    else
    {
        int x = height(root->left);
        int y = height(root->right);
        return x > y ? x + 1 : y + 1;
    }
}

void create_BST_from_preorder()
{
    
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
        printf("Enter an item to delete: ");
        scanf("%d", &x);
        delete_recurse(bst, x);
        printf("Deleted %d from tree.\n", x);
        if (bst->root == NULL)
            break;
        printf("Inorder: ");
        inorder_recurse(bst);
        printf("\n");
    }
    printf("Program Ended.\n");
}