#include <iostream>
#include <stack>
#include <math.h>
#include "QueueCPP.h"
#include "TreeNodeCPP.h"
using namespace std;

template <class T>
class Tree
{
    public:
    TreeNode<T> *root;
    Tree<T>() { root = NULL; }
    void create_tree();
    void preorder();
    void preorder_iter();
    void postorder();
    void inorder();
    void inorder_iter();
    void level_order();
    int num_nodes();
    int height();
    int num_leaf_nodes();
    private:
    int num_leaf_nodes_helper(TreeNode<T> *n);
    int height_helper(TreeNode<T> *n);
    int num_nodes_helper(TreeNode<T> *n);
    void inorder_helper(TreeNode<T> *n);
    void preorder_helper(TreeNode<T> *n);
    void postorder_helper(TreeNode<T> *n);
};

template <class T>
void Tree<T>::create_tree()
{
    TreeNode<T> *p, *t;
    T x;
    Queue<TreeNode<T>*> *queue = new Queue<TreeNode<T>*>();
    cout << "Enter root value: ";
    cin >> x;
    root = new TreeNode<T>(x);
    queue->enqueue(root);
    while(!queue->is_empty())
    {
        p = queue->dequeue();
        cout << "Enter Left Child of " << p->data << " or -1 for null: ";
        cin >> x;
        if (x != -1)
        {
            t = new TreeNode<T>(x);
            p->left = t;
            queue->enqueue(t);
        }
        cout << "Enter Right Child of " << p->data << " or -1 for null: ";
        cin >> x;
        if (x != -1)
        {
            t = new TreeNode<T>(x);
            p->right = t;
            queue->enqueue(t);
        }
    }
}

template <class T>
void Tree<T>::inorder()
{
    inorder_helper(root);
}

template <class T>
void Tree<T>::inorder_helper(TreeNode<T> *n)
{
    if (n)
    {
        inorder_helper(n->left);
        cout << n->data << " ";
        inorder_helper(n->right);
    }
}

template <class T>
void Tree<T>::inorder_iter()
{
    stack<TreeNode<T>*> *st = new stack<TreeNode<T>*>();
    TreeNode<T> *n = root;
    while (n != NULL || !st->empty())
    {
        if (n != NULL)
        {
            st->push(n);
            n = n->left;
        }
        else
        {
            n = st->top();
            st->pop();
            cout << n->data << " ";
            n = n->right;
        }
    }
}

template <class T>
void Tree<T>::preorder()
{
    preorder_helper(root);
}

template <class T>
void Tree<T>::preorder_helper(TreeNode<T> *n)
{
    if (n)
    {
        cout << n->data << " ";
        preorder_helper(n->left);
        preorder_helper(n->right);
    }
}

template <class T>
void Tree<T>::preorder_iter()
{
    stack<TreeNode<T>*> *st = new stack<TreeNode<T>*>();
    TreeNode<T> *n = root;
    while (n != NULL || !st->empty())
    {
        if (n != NULL)
        {
            cout << n->data << " ";
            st->push(n);
            n = n->left;
        }
        else
        {
            n = st->top();
            st->pop();
            n = n->right;
        }
    }
}

template <class T>
void Tree<T>::postorder()
{
    postorder_helper(root);
}

template <class T>
void Tree<T>::postorder_helper(TreeNode<T> *n)
{
    if (n)
    {
        postorder_helper(n->left);
        postorder_helper(n->right);
        cout << n->data << " ";
    }
}

template <class T>
void Tree<T>::level_order()
{
    Queue<TreeNode<T>*> *q = new Queue<TreeNode<T>*>();
    TreeNode<T> *n = root;
    q->enqueue(n);
    while (!q->is_empty())
    {
        n = q->dequeue();
        if (n == root) cout << n->data << " ";
        if (n->left)
        {
            cout << n->left->data << " ";
            q->enqueue(n->left);
        }
        if (n->right)
        {
            cout << n->right->data << " ";
            q->enqueue(n->right);
        }
    }
}

template <class T>
int Tree<T>::num_nodes()
{
    return num_nodes_helper(root);
}

template <class T>
int Tree<T>::num_nodes_helper(TreeNode<T> *n)
{
    if (n != NULL)
    {
        int x = num_nodes_helper(n->left);
        int y = num_nodes_helper(n->right);
        return x + y + 1;
    }
    return 0;
}

template <class T>
int Tree<T>::height()
{
    return height_helper(root);
}

template <class T>
int Tree<T>::height_helper(TreeNode<T> *n)
{
    if (n != NULL)
    {
        int x = height_helper(n->left);
        int y = height_helper(n->right);
        return max(x, y) + 1;
    }
    return -1;
}

template <class T>
int Tree<T>::num_leaf_nodes()
{
    return num_leaf_nodes_helper(root);
}

template <class T>
int Tree<T>::num_leaf_nodes_helper(TreeNode<T> *n)
{
    if (n != NULL)
    {
        int x = num_leaf_nodes_helper(n->left);
        int y = num_leaf_nodes_helper(n->right);
        return x == 0 && y == 0 ? 1 : x + y;
    }
    return 0;
}

int main()
{
    Tree<int> *tree = new Tree<int>();
    tree->create_tree();
    cout << "Inorder: ";
    tree->inorder_iter();
    cout << endl;
    cout << "Preorder: ";
    tree->preorder_iter();
    cout << endl;
    cout << "Level Order: ";
    tree->level_order();
    cout << endl;
    cout << "Number of Nodes: " << tree->num_nodes() << endl;
    cout << "Height of Tree: " << tree->height() << endl;
    cout << "Number of Leaf Nodes: " << tree->num_leaf_nodes() << endl;
}
