#include <stdio.h>
#define SIZE 10

int hash(int key)
{
    return key % SIZE;
}

int linear_probe(int HT[], int index)
{
    int i = 0;
    while (HT[(index + i) % SIZE] != 0) i++; 
    return (index + i) % SIZE;
}

void put(int HT[], int key)
{
    int index = hash(key);
    if (HT[index] != 0) index = linear_probe(HT, index);
    HT[index] = key;
}

int get(int HT[], int key)
{
    int index = hash(key);
    while (HT[index] != 0)
    {
        if (HT[index] == key) return 1;
        index = (index + 1) % SIZE;
    }
    return 0;
}

void print_array(int arr[], int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1) printf("%d", arr[i]);
        else printf("%d, ", arr[i]);
    }
    printf("]\n");
}

int main()
{
    int HashTable[10] = {0};
    put(HashTable, 12);
    put(HashTable, 25);
    put(HashTable, 35);
    put(HashTable, 8);
    put(HashTable, 26);
    print_array(HashTable, 10);
    // all these should print 1
    printf("%d\n", get(HashTable, 12));
    printf("%d\n", get(HashTable, 25));
    printf("%d\n", get(HashTable, 35));
    printf("%d\n", get(HashTable, 8));
    printf("%d\n", get(HashTable, 26));
    // all these should print 0
    printf("%d\n", get(HashTable, 11));
    printf("%d\n", get(HashTable, 62));
    printf("%d\n", get(HashTable, 87));
    printf("%d\n", get(HashTable, 2));
    printf("%d\n", get(HashTable, 1));
}