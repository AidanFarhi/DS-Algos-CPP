#include <stdlib.h>
#include <stdio.h>
#ifndef queue_h
#define queue_h

typedef struct TreeNode
{
    struct TreeNode *left;
    struct TreeNode *right;
    int data;
} TreeNode;

typedef struct Queue
{
    int capacity;
    int head;
    int tail;
    TreeNode **Q;
} Queue;

Queue* new_Queue(int size)
{
    Queue* queue = (Queue *) malloc(sizeof(Queue));
    queue->capacity = size;
    queue->head = queue->tail = 0;
    queue->Q = (TreeNode **) malloc(sizeof(TreeNode*) * size);
    return queue;
}

TreeNode* new_TreeNode()
{
    return (TreeNode*) malloc(sizeof(TreeNode));
}

int is_empty(Queue *q)
{
    return q->head == q->tail ? 1 : 0;
}

int is_full(Queue *q)
{
    return (q->tail+1) % q->capacity == q->head ? 1 : 0;
}

void enqueue(Queue *q, TreeNode *item)
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

TreeNode* dequeue(Queue *q)
{
    TreeNode *x = NULL;
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

#endif