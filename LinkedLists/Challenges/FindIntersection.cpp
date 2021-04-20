#include <iostream>
#include <stack>
using namespace std;

/**
 * Challenge: Find the intersection of 2 Linked Lists.
 */

class Node
{
    public:
    int data;
    Node *next;
    Node(int val) { data = val; }
};

int find_intersection(Node *h1, Node *h2)
{
    stack<Node*> list1_nodes;
    stack<Node*> list2_nodes;
    Node *n = h1;
    while (n)
    {
        list1_nodes.push(n);
        n = n->next;
    }
    n = h2;
    while (n)
    {
        list2_nodes.push(n);
        n = n->next;
    }
    Node *last_popped;
    while (list1_nodes.size() > 0 || list2_nodes.size() > 0)
    {
        if (list1_nodes.top() != list2_nodes.top())
            return last_popped->data;
        else
        {
            last_popped = list1_nodes.top();
            if (!list1_nodes.empty()) list1_nodes.pop();
            if (!list2_nodes.empty()) list2_nodes.pop();
        }
    }
    return -1;
}

int main()
{
    // Create to Linked lists
    Node *head1 = new Node(2);
    Node *tail1 = head1;

    Node *head2 = new Node(20);
    Node *tail2 = head2;
    // add some nodes to first list
    for (int i = 3; i < 15; i++)
    {
        tail1->next = new Node(i);
        tail1 = tail1->next;
    }
    // add some nodes to the second list
    for (int i = 25; i < 30; i++)
    {
        tail2->next = new Node(i);
        tail2 = tail2->next;
    }

    // now make the first lists tail point to the tail of the first list (29)
    tail1->next = tail2;

    // now add some more nodes to the second list
    for (int i = 44; i < 52; i++)
    {
        tail2->next = new Node(i);
        tail2 = tail2->next;
    }
    // THE INTERSECTION IS NODE WITH DATA: 29
    cout << find_intersection(head1, head2) << endl;
}

