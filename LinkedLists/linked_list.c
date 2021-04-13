#include <stdio.h>
#include <stdlib.h>

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

/* Function Prototypes */

LinkedList* new_linked_list();
Node* new_node(int val);
void insert_front(LinkedList *ll, int val);
void insert_end(LinkedList *ll, int val);
void insert_at(LinkedList *ll, int index, int val);
void traverse(LinkedList *ll);
void recursive_traverse(Node *node);
void recursive_reverse_traverse(Node *node);
int sum(LinkedList *ll);
float average(LinkedList *ll);
int max(LinkedList *ll);
int min(LinkedList *ll);
int search(LinkedList *ll, int target);

/* Function Implementations */

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

/* Insert a new node to the end of the Linked List. O(1) Time. */
void insert_end(LinkedList *ll, int val)
{
    if (ll->head == NULL) { insert_front(ll, val); }
    else
    {
        Node *nn = new_node(val);
        ll->tail->next = nn;
        ll->tail = nn;
    }
    ll->size++;
}

/* Prints all nodes starting from the head. O(N) time | O(1) space */
void traverse(LinkedList *ll)
{
    Node *current = ll->head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/* Prints all nodes starting from the head. O(N) time | O(N) space */
void recursive_traverse(Node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        recursive_traverse(node->next);
    }
}

/* Prints all nodes in reverse order. O(N) time | O(N) space */
void recursive_reverse_traverse(Node *node)
{
    if (node != NULL)
    {
        recursive_reverse_traverse(node->next);
        printf("%d ", node->data);
    }
}

/* Returns sum of all nodes in linked list. O(N) Time | O(1) Space */
int sum(LinkedList *ll)
{
    if (ll->head == NULL) return 0;
    int result = 0;
    Node *n = ll->head;
    while (n != NULL)
    {
        result += n->data;
        n = n->next;
    }
    return result;
}

/* Returns average of all nodes in linked list. O(N) Time | O(1) Space */
float average(LinkedList *ll)
{
    float total = (float) sum(ll);
    if (total > 0)
        return total / (float) ll->size;
    return 0;
}

/* Returns max node in Linked list. O(N) Time | O(1) Space */
int max(LinkedList *ll)
{
    if (ll->head == NULL) return 0;
    int maximum = ll->head->data;
    Node *n = ll->head;
    while (n != NULL)
    {
        if (n->data > maximum)
            maximum = n->data;
        n = n->next;
    }
    return maximum;
}

/* Returns min node in Linked list. O(N) Time | O(1) Space */
int min(LinkedList *ll)
{
    if (ll->head == NULL) return 0;
    int minimum = ll->head->data;
    Node *n = ll->head;
    while (n != NULL)
    {
        if (n->data < minimum)
            minimum = n->data;
        n = n->next;
    }
    return minimum;
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

/* Inserts a new node at a given index. */
void insert_at(LinkedList *ll, int index, int val)
{
    if (!(index < 0) || !(index > ll->size))
    {
        if (index == ll->size) { insert_end(ll, val); }
        else if (index == 0) { insert_front(ll, val); }
        else
        {
            int index_count = 0;
            Node *n = ll->head;
            Node *nn = new_node(val);
            Node *prev = NULL;
            while (index_count != index)
            {
                prev = n;
                n = n->next;
                index_count++;
            }
            prev->next = nn;
            nn->next = n;
        }
    }
}

int main()
{
    LinkedList *ll = new_linked_list();
    insert_front(ll, 33);
    insert_front(ll, 22);
    insert_front(ll, 11);
    insert_end(ll, 44);
    insert_end(ll, 55);
    insert_end(ll, 66);
    traverse(ll);
    recursive_traverse(ll->head);
    printf("\n");
    recursive_reverse_traverse(ll->head);
    printf("\n");
    printf("LL size: %d\n", ll->size);
    printf("Sum: %d\n", sum(ll));
    printf("Average: %.2f\n", average(ll));
    printf("Max node: %d\n", max(ll));
    printf("Min node: %d\n", min(ll));
    printf("Search for %d: %d\n", 55, search(ll, 55));
    printf("Search for %d: %d\n", 66, search(ll, 66));
    printf("Search for %d: %d\n", 42, search(ll, 42));
    insert_at(ll, 2, 99);
    insert_at(ll, 0, 100);
    insert_at(ll, ll->size, 999);
    traverse(ll);
}