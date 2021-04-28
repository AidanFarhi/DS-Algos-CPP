#include <iostream>
using namespace std;

/**
 * __________________
 * - Priority Queue -
 * ------------------
 * Implemented using Doubly Linked Lists. 
 * 
 * There are 5 Queues, each labeled by priority. 
 * 1 == highest priority - 5 == lowest priority
 * 
 * All Operations (except display()) take O(1) Time
 * Operations:
 * 
 * enqueue(item, priority) - Pushes item to Q<n> where n == priority
 * dequeue() - Returns and removes item with highest priority that is next in queue
 * next() - Returns item that is next in queue
 * display() - Prints to std output a visual representation of each queue
 * 
 */

template <class T>
class Node
{
    public:
    T data;
    Node<T> next;
    Node<T> prev;
    Node<T>(T item)
    {
        data = item;
        next = NULL;
        prev = NULL;
    }
};

template <class T>
class DLL
{
    public:
    Node<T> *head;
    Node<T> *tail;
    DLL<T>() { head = tail = NULL; }
    void push_front(T item);
    T pop_back();
    bool is_empty();
};

template <class T>
class PriorityQ
{
    public:
    DLL<T> *Q1; 
    DLL<T> *Q2;
    DLL<T> *Q3;
    DLL<T> *Q4;
    DLL<T> *Q5;
    PriorityQ<T>()
    {
        Q1 = new DLL<T>();
        Q2 = new DLL<T>();
        Q3 = new DLL<T>();
        Q4 = new DLL<T>();
        Q5 = new DLL<T>();
    }
    void enqueue(T item, int priority);
    T dequeue();
    T next();
    void display();
};

