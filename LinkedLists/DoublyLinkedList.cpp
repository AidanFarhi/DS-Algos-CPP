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
        if (head == NULL || size == 0)
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

    int pop_head()
    {
        if (!head) return 0; // If list is empty
        int data = head->data; // data to be returned
        if (size == 1)  // If there is only one item
        {
            head->next = NULL;
            tail->prev = NULL;
            head = NULL;
            tail = NULL;
        } else
        {
            Node *t = head;
            head = head->next;
            head->prev = NULL;
            t->next = NULL;
            t = NULL;
            if (size == 2) tail->prev = NULL;
        }
        size--;
        return data;
    }

    int pop_tail()
    {
        if (!tail) return 0; // If list is empty
        else if (size == 1) { pop_head(); }
        else
        {
            int data = tail->data;
            Node *t = tail;
            tail = tail->prev;
            tail->next = NULL;
            t->prev = NULL;
            t = NULL;
            if (size == 2) head->next = NULL;
            size--;
            return data;
        }
    }

    void reverse()
    {
        if (size > 1)
        {
            tail = head;
            Node *n = head;
            Node *prev;
            Node *t;
            while (n)
            {
                prev = n;
                t = n->next;
                n->next = n->prev;
                n->prev = t;
                n = t;
            }
            head = prev;
        }
    }

    int delete_at(int index)
    {
        if (index == 0) { pop_head(); }
        else if (index == size-1) { pop_tail(); }
        else if (index > 0 && index < size-1)
        {
            Node *n = head;
            for (int i = 0; i < index; i++)
                n = n->next;
            int data = n->data;
            n->prev->next = n->next;
            n->next->prev = n->prev;
            delete n;
            size--;
            return data;
        } else { return 0; }
    }

    ~DLL()
    {
        Node *n = head;
        while (n)
        {
            Node *t = n->next;
            delete n;
            n = t;
        }
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    DLL *dll = new DLL(arr, 6);
    dll->delete_at(3);
    dll->traverse_forward();
    dll->traverse_backward();
    dll->~DLL();
}

