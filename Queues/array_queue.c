#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int capacity;
    int head;
    int tail;
    int *Q;
} Queue;

Queue* new_Queue(int size)
{
    Queue* queue = (Queue *) malloc(sizeof(Queue));
    queue->capacity = size;
    queue->head = queue->tail = 0;
    queue->Q = (int *) malloc(sizeof(int) * size);
    return queue;
}

int is_empty(Queue *q)
{
    return q->head == q->tail ? 1 : 0;
}

int is_full(Queue *q)
{
    return (q->tail+1) % q->capacity == q->head ? 1 : 0;
}

void enqueue(Queue *q, int item)
{
    if (is_full(q))
        printf("Queue is full.\n");
    else
    {
        // This enables the queue to be circular
        q->tail = (q->tail + 1) % q->capacity;
        q->Q[q->tail] = item;
    }
};

int dequeue(Queue *q)
{
    int x = -1;
    if (is_empty(q))
        printf("Queue is empty.\n");
    else
    {
        // This enables the queue to be circular
        q->head = (q->head + 1) % q->capacity;
        x = q->Q[q->head];
    }
    return x;
}

void display(Queue *q)
{
    for (int i = q->head+1; i <= q->tail; i++)
        printf("%i ", q->Q[i]);
    printf("\n");
}

int main()
{
    int buffer;
    printf("Enter size of Queue: ");
    scanf("%i", &buffer);
    Queue *queue = new_Queue(buffer);
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
    free(queue->Q);
    free(queue);
}