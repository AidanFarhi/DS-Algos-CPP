#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int d) { data = d; next = NULL; }
};

class LinkedStack
{
    public:
    int size;
    Node *top;
    LinkedStack() { size = 0; top = NULL; }
    void push(int item);
    int pop();
    int peek_top();
    bool empty();
};  

void LinkedStack::push(int item)
{
    Node *n = new Node(item);
    if (top == NULL) top = n;
    else
    {
        n->next = top;
        top = n;
    }
    size++;
}

int LinkedStack::pop()
{
    int data = 0;
    if (top != NULL)
    {
        Node *t = top;
        data = top->data;
        top = top->next;
        delete t;
        size--;
    }
    return data;
}

int LinkedStack::peek_top()
{
    if (top) return top->data;
    return 0;
}

bool LinkedStack::empty()
{
    return top == NULL ? true : false;
}

int main()
{
    // Reverse and array using a stack
    int *arr = new int[5];
    for (int i = 0; i < 5; i++) arr[i] = i+1;
    LinkedStack *LS = new LinkedStack();
    for (int i = 0; i < 5; i++) 
    {
        LS->push(arr[i]);
        cout << arr[i] << " ";
        if (i == 4) cout << endl;
    }
    cout << "Top of stack: " << LS->peek_top() << endl;
    for (int i = 0; i < 5; i++)
    {
        arr[i] = LS->pop();
        cout << arr[i] << " ";
        if (i == 4) cout << endl;
    }
}
