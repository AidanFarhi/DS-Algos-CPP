#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) { data = val; }
};

class CircLL
{
public:
    Node *head;
    Node *tail;
    int size;
    CircLL() { size = 0; }
    /* Constructs a Circular linked list from an array */
    CircLL(int *arr, int n)
    {
        Node *t;
        head = new Node(arr[0]);
        head->next = head;
        tail = head;
        for (int i = 1; i < n; i++)
        {
            t = new Node(arr[i]);
            t->next = tail->next;
            tail->next = t;
            tail = t;
        }
        size = n;
    }
    void display()
    {
        Node *n = head;
        do
        {
            cout<< n->data << " ";
            n = n->next;
        } while (n != head);
        cout<<endl;
    }
    /* Displays linked list given num times */
    void displayNCycles(int num)
    {
        Node *n = head;
        for (int i = 0; i < size*num; i++)
        {
            cout << n->data << " ";
            n = n->next;
        }   
        cout << endl;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    CircLL *cll = new CircLL(arr, 5);
    cll->display();
    cll->displayNCycles(3);
    cout << cll->tail->next->data << endl;
    cout << cll->head->next->data << endl;
    cout << cll->head << endl;
    cout << cll->tail << endl;
}