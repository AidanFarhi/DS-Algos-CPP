#include <iostream>
#include <vector>
using namespace std;

/**
 * Challenge: Find the middle node of a linked list.
 */

class Node
{
    public:
    int data;
    Node *next;
    Node(int val) { data = val; }
};

int two_pass_method(Node *head)
{
    int size = 0;
    Node *n = head;
    while (n)
    {
        size++;
        n = n->next;
    }
    int mid = size / 2;
    if (size % 2 == 0) mid--;
    n = head;
    for (int i = 0; i < mid; i++)
        n = n->next;
    return n->data;
}

int one_pass_method(Node *head)
{
    Node *slow, *fast;
    slow = fast = head;
    while (fast)
    {
        fast = fast->next;           // move once
        if (fast) fast = fast->next; // move again
        if (fast) slow = slow->next; // if fast is not null, then move slow
    }
    return slow->data;
}

int with_vector_method(Node *head)
{
    vector<Node*> nodes;
    Node *n = head;
    while (n)
    {
        nodes.push_back(n);
        n = n->next;
    }
    int mid = nodes.size() / 2;
    if (nodes.size() % 2 == 0) mid--;
    return nodes.at(mid)->data;
}

int main()
{
    Node *head = new Node(1);
    Node *tail = head;
    for (int i = 2; i < 10; i++)
    {
        tail->next = new Node(i);
        tail = tail->next;
    }
    Node *n = head;
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
    cout << one_pass_method(head) << endl;
    cout << two_pass_method(head) << endl;
    cout << with_vector_method(head) << endl;
}