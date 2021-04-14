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
void insert_sorted(LinkedList *ll, int val);
void remove_duplicates_sorted(LinkedList *ll);
int pop_front(LinkedList *ll);
int pop_back(LinkedList *ll);
void traverse(LinkedList *ll);
void recursive_traverse(Node *node);
void recursive_reverse_traverse(Node *node);
int sum(LinkedList *ll);
float average(LinkedList *ll);
int max(LinkedList *ll);
int min(LinkedList *ll);
int search(LinkedList *ll, int target);
int is_sorted(LinkedList *ll);
void reverse_list_array(LinkedList *ll);
void reverse_list_pointers(LinkedList *ll);
void reverse_list_recursive(LinkedList *ll, Node *cur, Node *prev);
void append_list(LinkedList *ll1, LinkedList* ll2);
LinkedList* merge_sorted_lists(LinkedList *ll1, LinkedList *ll2);

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
        ll->tail->next = NULL;
        ll->size++;
    }
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
        ll->size++;
    }
}

/* Insert a new node into a sorted increase ordered LinkedList */
void insert_sorted(LinkedList *ll, int val)
{
    if (ll->head == NULL) { insert_front(ll, val); }
    else
    {
        Node *n = ll->head;
        while (n != NULL)
        {
            if (n->data > val)
            {
                Node *nn = new_node(n->data);
                nn->next = n->next;
                n->data = val;
                n->next = nn;
                break;
            }
            n = n->next;
        }
        if (n == NULL) { insert_end(ll, val); }
        else ll->size++;
    }
}

/* Removes and returns node at front of Linked List. If list is empty, returns 0. O(1) Time */
int pop_front(LinkedList *ll)
{
    if (ll->head == NULL) return 0;
    Node *t = ll->head;
    int data = t->data;
    ll->head = ll->head->next;
    free(t);
    ll->size--;
    return data;
}

/* Removes and returns node at end of Linked List. If list is empty, returns 0. O(N) Time */
int pop_back(LinkedList *ll)
{
    if (ll->tail == NULL) return 0;
    Node *n = ll->head;
    Node *prev = NULL;
    int data;
    while (n->next != NULL)
    { 
        prev = n;
        n = n->next;
    }
    data = n->data;
    if (n == ll->head)
    {
        free(ll->head);
        ll->head = NULL;
        ll->tail = NULL;
    } else
    {
        free(n);
        prev->next = NULL;
        ll->tail = prev;
    }
    return data;
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

/* Returns 1 if Linked List is sorted (ascending) | 0 if not. */
int is_sorted(LinkedList *ll)
{
    if (ll->head == NULL) return 0;
    Node *n = ll->head;
    Node *prev = NULL;
    while (n != NULL)
    {
        if (prev != NULL)
            if (prev->data > n->data)
                return 0;
        prev = n;
        n = n->next;
    }
    return 1;
}

/* Removes duplicates from a sorted (ascending) Linked List */
void remove_duplicates_sorted(LinkedList *ll)
{
    if (ll->size > 1)
    {
        Node *n = ll->head->next;
        Node *prev = ll->head;
        while (n != NULL)
        {
            if (prev->data == n->data)
            {
                prev->next = n->next;
                free(n);
                n = prev->next;
            } else
            {
                prev = n;
                n = n->next;
            }
        }
    }
}

/* Reverse a linked list using an auxiliary array */
void reverse_list_array(LinkedList *ll)
{
    Node* *arr = malloc(sizeof(Node*) * ll->size);
    Node *n = ll->head;
    for (int i = 0; i < ll->size; i++)
    {
        arr[i] = n;
        n = n->next;
    }
    int l = 0;
    int r = ll->size-1;
    while (l < r)
    {
        int temp = arr[l]->data;
        arr[l++]->data = arr[r]->data;
        arr[r--]->data = temp;
    }
    free(arr);
}

/* Reverse a linked list using sliding pointers */
void reverse_list_pointers(LinkedList *ll)
{
    Node *p = ll->head;
    Node *q = NULL;
    Node *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    ll->head = q;
}

/* Reverse a linked list using recursion */
void reverse_list_recursive(LinkedList *ll, Node *cur, Node *prev)
{
    if (prev != NULL)
    {
        reverse_list_recursive(ll, prev, prev->next);
        prev->next = cur;
    }
    else
    {
        ll->head = cur;
    }
}

/* Adds second given list to the end of the first list */
void append_list(LinkedList *ll1, LinkedList* ll2)
{
    ll1->tail->next = ll2->head;
}

/* Merge two sorted lists */
LinkedList* merge_sorted_lists(LinkedList *ll1, LinkedList *ll2)
{
    Node *m_head = NULL;
    Node *m_tail = NULL;
    Node *ll1_head = ll1->head;
    Node *ll2_head = ll2->head;
    // First determine which node should be the new merged head
    if (ll1->head->data < ll2->head->data)
    {
        m_head = ll1_head;
        ll1_head = ll1_head->next;
    }
    else
    {
        m_head = ll2->head;
        ll2_head = ll2->head->next;
    }
    m_tail = m_head;
    // Now merge the lists
    while (ll1_head != NULL || ll2_head != NULL)
    {
        if (ll1_head != NULL && ll2_head != NULL)
        {
            if (ll1_head->data < ll2_head->data)
            {
                m_tail->next = ll1_head;
                m_tail = ll1_head;
                ll1_head = ll1_head->next;
            }
            else
            {
                m_tail->next = ll2_head;
                m_tail = ll2_head;
                ll2_head = ll2_head->next;
            }
        }
        else if (ll1_head != NULL)
        {
            m_tail->next = ll1_head;
            m_tail = ll1_head;
            ll1_head = ll1_head->next;
        }
        else
        {
            m_tail->next = ll2_head;
            m_tail = ll2_head;
            ll2_head = ll2_head->next;
        }
    }
    LinkedList *merged = new_linked_list();
    merged->head = m_head;
    merged->size = ll1->size + ll2->size;
    return merged;
}

int main()
{
    LinkedList *ll1 = new_linked_list();
    insert_end(ll1, 11);
    insert_end(ll1, 22);
    insert_end(ll1, 33);
    insert_end(ll1, 44);
    insert_end(ll1, 55);
    insert_end(ll1, 66);
    insert_end(ll1, 77);
    insert_end(ll1, 88);
    LinkedList *ll2 = new_linked_list();
    insert_end(ll2, 33);
    insert_end(ll2, 44);
    insert_end(ll2, 55);
    insert_end(ll2, 88);
    insert_end(ll2, 99);
    insert_end(ll2, 100);
    insert_end(ll2, 200);
    insert_end(ll2, 300);
    LinkedList *merged = merge_sorted_lists(ll1, ll2);
    traverse(merged);
}