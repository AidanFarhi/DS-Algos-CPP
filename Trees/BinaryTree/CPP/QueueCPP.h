#include <iostream>
using namespace std;

#ifndef QueueCPP_h
#define QueueCPP_h

/**
 * _________
 * | Queue |
 * ---------
 * - The underlying Data Structure is a Doubly Linked List -
 * 
 * Operations:
 * 
 * enqueue() - O(1)
 * dequeue()   - O(1)
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
class Queue
{
    public:
    Node<T> *head;
    Node<T> *tail;
    void enqueue(T item);
    T dequeue();
    bool is_empty();
    Queue<T>() { head = tail = NULL; }
};

template <class T>
void Queue<T>::enqueue(T item)
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
T Queue<T>::dequeue()
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
bool Queue<T>::is_empty()
{
    return head == NULL ? true : false;
}

#endif