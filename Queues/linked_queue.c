#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

typedef struct LinkedQ
{
    Node *head;
    Node *tail;
} LinkedQ;

/* Function Prototypes */
Node* new_Node(int data);
LinkedQ* new_LinkedQ();
void enqueue(LinkedQ *q, int data);
int dequeue(LinkedQ *q);
int empty(LinkedQ *q);
void display(LinkedQ *q);

Node* new_Node(int data)
{
    Node *n = (Node *) malloc(sizeof(Node));
    n->data = data;
    return n;
}

LinkedQ* new_LinkedQ()
{
    LinkedQ* q = (LinkedQ*) malloc(sizeof(LinkedQ));
    return q;
}

void enqueue(LinkedQ *q, int data)
{
    Node *new_node = new_Node(data);
    if (empty(q))
        q->head = q->tail = new_node;
    else
    {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

int dequeue(LinkedQ *q)
{
    int data = -1;
    Node *n;
    if (empty(q))
        printf("Queue is empty\n");
    else
    {
        n = q->head;
        q->head = q->head->next;
        data = n->data;
        free(n);
    }
    return data;
}

int empty(LinkedQ *q)
{
    return q->head == NULL ? 1 : 0;
}

void display(LinkedQ *q)
{
    Node *n = q->head;
    while (n)
    {
        printf("%i ", n->data);
        n = n->next;
    }
    printf("\n");
}

int main()
{
    int buffer;
    LinkedQ *queue = new_LinkedQ();
    printf("Enter number of elements to enqueue: ");
    scanf("%i", &buffer);
    int item;
    for (int i = 0; i < buffer; i++)
    {
        printf("Enter item: ");
        scanf("%i", &item);
        enqueue(queue, item);
    }
    printf("Queue: ");
    display(queue);
    printf("Enter number of items to dequeue: ");
    scanf("%i", &buffer);
    for (int i = 0; i < buffer; i++)
    {
        printf("Item: %i\n", dequeue(queue));
    }
    printf("After removal: ");
    display(queue);
}

