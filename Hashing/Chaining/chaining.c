#include <stdio.h>
#include "chains.h"

/* Function Prototypes */
int hash(int key);
void put(LinkedList** HashTable, int key);
int get(LinkedList** HashTable, int key);

int hash(int key)
{
    return key % 10;
}

void put(LinkedList** HashTable, int key)
{
    int index = hash(key);
    insert_front(HashTable[index], key);
}

/* Returns 1 if found or 0 if not found */
int get(LinkedList** HashTable, int key)
{
    int index = hash(key);
    return search(HashTable[index], key);
}

int main()
{
    LinkedList **HashTable = (LinkedList**) malloc(sizeof(LinkedList*) * 10);
    int i;

    // Initialize a HashTable of size 10
    for (i = 0; i < 10; i++)
        HashTable[i] = (LinkedList*) malloc(sizeof(LinkedList));

    // Insert the keys into the table
    int keys[] = {1, 34, 2, 56, 16, 14, 76, 40};
    for (i = 0; i < 8; i++)
        put(HashTable, keys[i]);
    
    // Test
    printf("34 in Table: %d\n", get(HashTable, 34));
    printf("14 in Table: %d\n", get(HashTable, 14));
    printf("78 in Table: %d\n", get(HashTable, 78));
    printf("56 in Table: %d\n", get(HashTable, 56));
    printf("9 in Table: %d\n", get(HashTable, 9));
    printf("2 in Table: %d\n", get(HashTable, 2));
    printf("16 in Table: %d\n", get(HashTable, 16));
}