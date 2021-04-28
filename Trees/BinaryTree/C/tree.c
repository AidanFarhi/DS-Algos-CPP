#include <stdio.h>
#include "queue.h"

TreeNode *root = NULL;

void create()
{
    TreeNode *p, *t;
    int x;
    // Create a new queue of size 50
    Queue *queue = new_Queue(50);
    printf("Enter root value: ");
    scanf("%d", &x);
    root = new_TreeNode();
    root->data = x;
    root->left = root->right = NULL;
    enqueue(queue, root);

    while(!is_empty(queue))
    {
        p = dequeue(queue);
        printf("Enter Left Child of %d or -1 for null: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new_TreeNode();
            t->data = x;
            t->left = t->right = NULL;
            p->left = t;
            enqueue(queue, t);
        }
        printf("Enter Right Child of %d or -1 for null: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new_TreeNode();
            t->data = x;
            t->left = t->right = NULL;
            p->right = t;
            enqueue(queue, t);
        }
    }
}

void preorder(TreeNode *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(TreeNode *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void postorder(TreeNode *node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

void levelorder(TreeNode *node)
{
    
}

int main()
{
    create();
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n");
}