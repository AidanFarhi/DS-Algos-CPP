#include <stdlib.h>
#include <stdio.h>

/* Max Heap Structure */
typedef struct MaxHeap
{
    int *hp;
    int capacity;
    int n;
} MaxHeap;

/* Create a new Max Heap struct */
MaxHeap* new_MaxHeap(int size)
{
    MaxHeap* heap = (MaxHeap*) malloc(sizeof(MaxHeap));
    heap->capacity = size;
    heap->hp = (int*) malloc(sizeof(int) * (size + 1));
    heap->n = 0;
    return heap;
}

/* Function Prototypes */

void insert(MaxHeap* heap, int item);
int pop_max(MaxHeap* heap);
void sink(MaxHeap* heap);
void swim(MaxHeap* heap); 
MaxHeap* heapify(int *arr, int n); 
// int* heap_sort(int *arr);
void swap(int *arr, int i, int j); 

/* Function Implementations */

void insert(MaxHeap* heap, int item)
{
    if (heap->n < heap->capacity)
    {
        heap->hp[++heap->n] = item;
        swim(heap);
    }
}

void swim(MaxHeap* heap)
{
    int i = heap->n;
    while (i > 1 && heap->hp[i] > heap->hp[i/2])
    {
        swap(heap->hp, i, i/2);
        i = i/2;
    }
}

int pop_max(MaxHeap* heap)
{
    int max_item = -1;
    if (heap->n >= 1)
    {
        max_item = heap->hp[1];
        swap(heap->hp, 1, heap->n--);
        sink(heap);
    }
    return max_item;
}

void sink(MaxHeap* heap)
{
    int i = 1;
    int j = 2;
    while (j <= heap->n) // keep checking down the tree as long as i has a child
    {
        if (j < heap->n && heap->hp[j] < heap->hp[j+1]) j++; // Find out which child is greater
        if (heap->hp[i] < heap->hp[j])
        {
            swap(heap->hp, i, j); // swap parent and greater child
            i = j;                // set i to where greater child was
            j = i * 2;            // set j to the new left child of i
        } else break;
    }
}

// Creates a heap out of an array and returns a MaxHeap struct
MaxHeap* heapify(int *arr, int n)
{
    // i will start at middle of arr because 
    // all leaf node indexes start at n // 2
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        int j = (i * 2) + 1; // current left child of i
        while (j <= n) // while there is still a valid child to check
        {
            if (j < n && arr[j+1] > arr[j]) j++; // check which child is greater
            if (arr[i] < arr[j]) // if parent is less than child
            {
                swap(arr, i, j); // swap parent and child
                i = j;           // move i down to where greater child was
                j = (i * 2) + 1;       // move j to the new left child of i
            } else break;
        }
    }
    MaxHeap *heap = new_MaxHeap(n); // Create a new MaxHeap struct
    for (int i = 0; i < n; i++)     // Now copy elements of arr into heap
        heap->hp[i+1] = arr[i];
    heap->n = n;
    return heap;
}

void swap(int *arr, int i, int j)
{
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

int main()
{
    int nums[] = {1, 23, 55, 12, 56, 226, 2, -11, 66, 2555};
    MaxHeap* heap = heapify(nums, 10);
    printf("Max Item: %d\n", heap->hp[1]);
    for (int i = 0; i < 10; i++)
        printf("%d ", nums[i]);
    printf("\n");
}