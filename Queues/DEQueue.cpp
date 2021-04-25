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
    Node *next;
    Node(T d) { data = d; next = NULL; }
};

template <class T>
class DEQueue
{
    public:
    Node<T> *head;
    Node<T> *tail;
    DEQueue<T>() { head = tail = NULL; }
};

