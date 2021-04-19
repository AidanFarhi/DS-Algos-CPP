#include <iostream>
using namespace std;

class Node
{
    public:
    Node *next;
    Node *prev;
    int data;
    Node(int val) { data = val; }
    ~Node(){};
};

class DLL
{
    public:
    // Data members
    Node *head;
    Node *tail;
    int size;
    // Constructors
    DLL() { size = 0; }
    DLL(int *arr, int len)
    {
        head = new Node(arr[0]);
        tail = head;
        for (int i = 1; i < len; i++)
        {
            Node *nn = new Node(arr[i]);
            nn->prev = tail;
            tail->next = nn;
            tail = nn;
        }
        size = len;
    }
    // Methods
    void traverse_forward()
    {
        Node *n = head;
        while (n != NULL)
        {
            if (n->next)
                cout << n->data << " -> ";
            else
                cout << n->data;
            n = n->next;
        }
        cout << endl;
    }
    void traverse_backward()
    {
        Node *n = tail;
        while (n != NULL)
        {
            if (n->prev)
                cout << n->data << " -> ";
            else
                cout << n->data;
            n = n->prev;
        }
        cout << endl;
    }
    void insert_head(int val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            tail = head;
        } else
        {
            Node *nn = new Node(val);
            nn->next = head;
            head->prev = nn;
            head = nn;
        }
        size++;
    }
    void insert_tail(int val)
    {
        if (head == NULL) { insert_head(val); }
        else
        {
            Node *nn = new Node(val);
            tail->next = nn;
            nn->prev = tail;
            tail = nn;
            size++;
        }
    }
    void insert_at(int index, int val)
    {
        if (index == 0) { insert_head(val); }
        else if (index == size) { insert_tail(val); }
        else if (index > 0 && index < size)
        {
            Node *n = head;
            for (int i = 0; i < index; i++)
                n = n->next;
            Node *nn = new Node(val);
            nn->next = n;
            nn->prev = n->prev;
            n->prev->next = nn;
            n->prev = nn;
            size++;
        }
    }
    ~DLL(){}
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    DLL *dll = new DLL(arr, 7);
    dll->insert_at(0, 100);
    dll->insert_at(8, 99);
    dll->insert_at(8, 88);
    dll->traverse_forward();
    dll->traverse_backward();
}

