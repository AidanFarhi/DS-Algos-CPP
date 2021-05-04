#include <iostream>
using namespace std;

class Node
{
    public:
    Node *left;
    Node *right;
    int height;
    int data;
    Node(int item)
    {
        data = item;
        left = right = NULL;
        height = 1;
    }
};

class AVLTree
{
    public:
    Node *root;
    AVLTree() { root = NULL; }
    void rec_insert(int item);
    void delete_node(int item);
    Node* fix_tree(Node *n);
    Node* get_node_predecessor(Node *n);
    Node* get_node_successor(Node *n);
    int get_node_height(Node *n);
    int get_node_balance(Node *n);
    Node* LL_rotation(Node *n);
    Node* RR_rotation(Node *n);
    Node* RL_rotation(Node *n);
    Node* LR_rotation(Node *n);
    void rec_inorder();
    private:
    Node* delete_node_helper(Node *n, int item);
    Node* rec_insert_helper(Node *n, int item);
    void rec_inorder_helper(Node *n);
};

int AVLTree::get_node_height(Node *n)
{   
    if (n == NULL) return 0;
    int left_height = n && n->left ? n->left->height : 0;
    int right_height = n && n->right ? n->right->height : 0;
    return left_height > right_height ? left_height + 1 : right_height + 1;
}

int AVLTree::get_node_balance(Node *n)
{
    int left_height = n && n->left ? n->left->height : 0;
    int right_height = n && n->right ? n->right->height : 0;
    return left_height - right_height;
}

Node* AVLTree::get_node_predecessor(Node *n)
{
    if (n && n->right)
        return get_node_predecessor(n->right);
    return n;
}

Node* AVLTree::get_node_successor(Node *n)
{
    if (n && n->left)
        return get_node_successor(n->left);
    return n;
}

/* ROTATIONS */

Node* AVLTree::LL_rotation(Node *n)
{
    cout << "Performing LL rotation on Node: " << n->data << endl;
    Node *A = n;
    Node *B = n->left;
    Node *B_right = B->right;
    B->right = A;
    A->left = B_right;
    A->height = get_node_height(A);
    B->height = get_node_height(B);
    if (n == root) root = B;
    return B;
}

Node* AVLTree::RR_rotation(Node *n)
{
    cout << "Performing RR rotation on Node: " << n->data << endl;
    Node *A = n;
    Node *B = n->right;
    Node *B_left = B->left;
    B->left = A;
    A->right = B_left;
    A->height = get_node_height(A);
    B->height = get_node_height(B);
    if (n == root) root = B;
    return B;
}

Node* AVLTree::LR_rotation(Node *n)
{
    cout << "Performing LR rotation on Node: " << n->data << endl;
    Node *A = n;
    Node *B = n->left;
    Node *C = n->left->right;
    Node *C_left = C->left;
    Node *C_right = C->right;
    C->left = B;
    C->right = A;
    A->left = C_right;
    B->right = C_left;
    A->height = get_node_height(A);
    B->height = get_node_height(B);
    C->height = get_node_height(C);
    if (n == root) root = C;
    return C;
}

Node* AVLTree::RL_rotation(Node *n)
{
    cout << "Performing RL rotation on Node: " << n->data << endl;
    Node* A = n;
    Node* B = n->right;
    Node* C = n->right->left;
    Node* C_left = C->left;
    Node* C_right = C->right;
    C->left = A;
    C->right = B;
    A->right = C_left;
    B->left = C_right;
    if (n == root) root = C;
    A->height = get_node_height(A);
    B->height = get_node_height(B);
    C->height = get_node_height(C);
    return C;
}

void AVLTree::rec_insert(int item)
{
    root = rec_insert_helper(root, item);
}

Node* AVLTree::rec_insert_helper(Node *n, int item)
{
    if (n == NULL)
        return new Node(item);
    else if (n->data > item)
        n->left = rec_insert_helper(n->left, item);
    else if (n->data < item)
        n->right = rec_insert_helper(n->right, item);
    // After insertion, set new height
    n->height = get_node_height(n);
    n = fix_tree(n);
    return n;
}

void AVLTree::rec_inorder()
{
    if (root) rec_inorder_helper(root);
}

void AVLTree::rec_inorder_helper(Node *n)
{
    if (n->left)
        rec_inorder_helper(n->left);
    cout << n->data << " ";
    if (n->right)
        rec_inorder_helper(n->right);
}

void AVLTree::delete_node(int item)
{
    cout << "Deleting node: " << item << endl;
    root = delete_node_helper(root, item);
}

Node* AVLTree::delete_node_helper(Node* n, int item)
{
    if (n == NULL)
        return NULL;
    else if (n->data > item)
        n->left = delete_node_helper(n->left, item);
    else if (n->data < item)
        n->right = delete_node_helper(n->right, item);
    // Leaf Node case
    else if (n->left == NULL && n->right == NULL && n->data == item)
    {
        if (n == root)
            root = NULL;
        delete n;
        return NULL;
    }
    else
    {
        if (get_node_height(n->left) > get_node_height(n->right))
        {
            Node* t = get_node_predecessor(n->left);
            n->data = t->data;
            n->left = delete_node_helper(n->left, t->data);
        }
        else
        {
            Node* t = get_node_successor(n->right);
            n->data = t->data;
            n->right = delete_node_helper(n->right, t->data);
        }
    }
    n->height = get_node_height(n);
    n = fix_tree(n);
    return n;
}

Node* AVLTree::fix_tree(Node* n)
{
    int balance = get_node_balance(n);
    // Left inbalance
    if (balance == 2)
    {   // LL inbalance
        int left_balance = get_node_balance(n->left);
        if (left_balance <= 1)
            return LL_rotation(n); 
        else if (left_balance == -1) // LR inbalance
            return LR_rotation(n);
    }
    // Right inbalance
    if (balance == -2)
    {   // RR inbalance
        int right_balance = get_node_balance(n->right);
        if (right_balance >= -1)
            return RR_rotation(n);
        else if (right_balance == 1) // RL inbalance
            return RL_rotation(n);
    }
    return n;
} 

int main()
{
    AVLTree* avl = new AVLTree();
    for (int i = 0; i < 10; i++)
    {
        avl->rec_insert(i);
    }
    avl->rec_inorder();
    cout << endl;
    cout << "Root: " << avl->root->data << endl;
    cout << "Height: " << avl->get_node_height(avl->root) << endl;
    int x;
    while (true)
    {
        cout << "Enter an item to delete: ";
        cin >> x;
        avl->delete_node(x);
        avl->rec_inorder();
        cout << endl;
        if (avl->root == NULL)
            break;
        cout << "Root: " << avl->root->data << endl;
    }
    cout << "Program over." << endl;
}