#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
    ~Node() {}
};

class LinkedList
{
public:
    int size;
    Node *head;
    Node *tail;
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        tail = head;
    }
    void insert_front(int val);
    void insert_end(int val);
    void insert_at(int index, int val);
    void insert_sorted(int val);
    void remove_duplicates_sorted();
    int pop_front();
    int pop_back();
    void traverse();
    void recursive_traverse();
    void recursive_reverse_traverse();
    int sum();
    float average();
    int max();
    int min();
    int search(int target);
    int is_sorted();
    void reverse_list_array();
    void reverse_list_pointers();
    void reverse_list_recursive(Node *cur, Node *prev);
    void append_list(LinkedList* ll2);
    LinkedList* merge_sorted_lists(LinkedList *ll2);
    int has_loop();
    ~LinkedList();
};

/* Write all the functions here */