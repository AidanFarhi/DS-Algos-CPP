#include <stdio.h>
#include <stdlib.h>

/* Definition of a Node */
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

/* Initialize an empty head Node */
Node *head = NULL;

/* Function Prototypes */
void traverse();
void cleanup();

/* Main */
int main(void)
{
    // create a linked list of length 5
    for (int i = 0; i < 5; i++)
    {
        // add new nodes to head
        Node *new_node = malloc(sizeof(Node));
        new_node->data = (i + 1) * 100;
        new_node->next = head;
        head = new_node;
    }
    traverse();
    cleanup();
}

/* Linear traversal through Linked List */
void traverse()
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%i -> ", current->data);
        current = current->next;
    }
    printf("End\n");
}

/* Free up that memory */
void cleanup()
{
    Node *current = head;
    while (current != NULL)
    {
        Node *n = current->next;
        free(current);
        current = n;
    }
}