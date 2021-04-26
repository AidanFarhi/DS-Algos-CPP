#include <iostream>
using namespace std;

/**
 * ______________________
 * | Double Ended Queue |
 * ----------------------
 * - The underlying Data Structure is a Doubly Linked List -
 * 
 * Operations:
 * 
 * push_front() - O(1)
 * pop_front()  - O(1)
 * pop_back()   - O(1)
 * pop_front()  - O(1)
 * display()    - O(N)
 * 
 */

template <class T>
class Node
{
    public:
    T data;
    Node<T> *next;
    Node<T> *prev;
    Node<T>(T d) { data = d; next = NULL; prev = NULL; }
};

template <class T>
class DEQueue
{
    public:
    Node<T> *head;
    Node<T> *tail;
    void push_front(T item);
    T pop_front();
    void push_back(T item);
    T pop_back();
    void display();
    bool is_empty();
    DEQueue<T>() { head = tail = NULL; }
};

template <class T>
void DEQueue<T>::push_front(T item)
{
    Node<T> *new_node = new Node<T>(item);
    if (is_empty())
        head = tail = new_node;
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

template <class T>
T DEQueue<T>::pop_front()
{
    T data = NULL;
    if (!is_empty())
    {
        Node<T> *t = head;
        data = head->data;
        head = head->next;
        if (head) 
            head->prev = NULL;
        else
            tail = NULL;
        delete t;
    }
    return data;
}

template <class T>
void DEQueue<T>::push_back(T item)
{
    Node<T> *new_node = new Node<T>(item);
    if (is_empty())
        head = tail = new_node;
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

template <class T>
T DEQueue<T>::pop_back()
{
    T data = NULL;
    if (!is_empty())
    {
        Node<T> *t = tail;
        data = tail->data;
        tail = tail->prev;
        if (tail) 
            tail->next = NULL;
        else 
            head = NULL;
        delete t;
    }
    return data;
}

template <class T>
void DEQueue<T>::display()
{
    Node<T> *n = head;
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

template <class T>
bool DEQueue<T>::is_empty()
{
    return head == NULL ? true : false;
}

int main()
{
    int buffer;
    DEQueue<int> *queue = new DEQueue<int>();
    while (1)
    {
        printf("Enter number of elements to enqueue (or -1 to quit): ");
        cin >> buffer;
        if (buffer < 0) break;
        int item;
        for (int i = 0; i < buffer; i++)
        {
            cout << "Enter item: ";
            cin >> item;
            queue->push_back(item);
        }
        cout << "Queue: ";
        queue->display();
        cout << "Enter number of items to dequeue: ";
        cin >> buffer;
        for (int i = 0; i < buffer; i++)
        {
            if (i % 2 == 0)
                cout << "Front Item: " << queue->pop_front() << endl;
            else
                cout << "Back Item: " << queue->pop_back() << endl;
        }
        cout << "After removal: ";
        queue->display();
    }
    cout << "End of program." << endl;
}