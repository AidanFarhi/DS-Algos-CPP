#include <stdlib.h>

#ifndef chains_h
#define chains_h

/* Linked List Node */
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

/* Linked List */
typedef struct LinkedList
{
    int size;
    Node *head;
    Node *tail;
} LinkedList;

LinkedList* new_linked_list();
Node* new_node(int val);
void insert_front(LinkedList *ll, int val);
int search(LinkedList *ll, int target);

/* Creates and initilizes a new Linked List on the heap */
LinkedList* new_linked_list()
{
    LinkedList *ll = (LinkedList *)malloc(sizeof(LinkedList));
    ll->size = 0;
    return ll;
}

/* Creates a new node on heap */
Node* new_node(int val)
{
    Node* nn = (Node*)malloc(sizeof(Node));
    nn->data = val;
    return nn;
}

/* Insert a new node to the front of the Linked List. O(1) Time. */
void insert_front(LinkedList *ll, int val)
{
    if (ll->head == NULL)
    {
        ll->head = new_node(val);
        ll->tail = ll->head;
    } else
    {
        Node *nn = new_node(val);
        nn->next = ll->head;
        ll->head = nn;
    }
    ll->size++;
}

/* Searches for a node in linked list. Returns -> 1 if found | -> 0 if not found */
int search(LinkedList *ll, int target)
{
    if (ll->head == NULL) return 0;
    Node *n = ll->head;
    while (n != NULL)
    {
        if (n->data == target) 
        {
            // move found node to head to improve future search time
            int t = ll->head->data;
            ll->head->data = n->data;
            n->data = t;
            return 1;
        }
        n = n->next;
    }
    return 0;
}

#endif