#include <stdio.h>
#include <stdlib.h>

/* Array Structure */
struct Array
{
    int A[10];  // array of default size 10
    int size;   // size of array
    int length; // number of elements currently in array
};

/* Print Array in std output */
void Display(struct Array *arr) // O(N)
{
    printf("[");
    for (int i = 0; i < arr->length; i++)
    {
        if (i == arr->length - 1) { printf("%d]\n", arr->A[i]); break; }
        printf("%d, ", arr->A[i]);
    }
}

/* Add item to end of an array */
void Append(struct Array *arr, int item) // O(1)
{
    if (arr->length < arr->size)      // first check if array is full
        arr->A[arr->length++] = item; // add item to the end
}

/* Insert an item at a given index */
void Insert(struct Array *arr, int index, int item) // O(N)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; --i)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = item;
        arr->length++;
    }
}

/* Delete an item at a given index */
int Delete(struct Array *arr, int index) // O(N)
{
    int output = 0;
    if (index >= 0 && index <= arr->length)
    {
        output = arr->A[index];
        for (int i = index; i < arr->length-1; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
    }
    return output;
}

/* Swap two array elements */
void Swap(struct Array *arr, int i, int j)
{
    int temp = arr->A[i];
    arr->A[i] = arr->A[j];
    arr->A[j] = temp;
}

/* Returns 0 (index of item) if found item or -1 if not found */
int LinearSearch(struct Array *arr, int item) // O(N)
{
    for (int i = 0; i < arr->length; i++)
        if (arr->A[i] == item)
        {
            Swap(arr, i, 0); // optimize for future searches
            return 0;
        } 
    return -1;
}

/* Returns index of item if found or -1 if not found. !! Array must be sorted !! */
int IterativeBinarySearch(struct Array *arr, int target) // O(logN)
{
    int lo = 0;
    int hi = arr->length;
    int mid;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (arr->A[mid] == target)
            return mid;
        else if (arr->A[mid] > target)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return -1;
}

/* Returns index of item if found or -1 if not found. !! Array must be sorted !! */
int RecursiveBinarySearch(struct Array *arr, int lo, int hi, int target)
{
    if (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (arr->A[mid] == target)
            return mid;
        else if (arr->A[mid] > target)
            return RecursiveBinarySearch(arr, lo, mid-1, target);
        else
            return RecursiveBinarySearch(arr, mid+1, hi, target);
    }
    return -1;
}

/* Returns element at given index or -1 if given index is not valid or element is not found */
int Get(struct Array *arr, int index)
{
    if (index > 0 && index < arr->length) return arr->A[index];
    return -1;
}

/* Replaces element at given index. Returns index if successful or -1 if not */
int Set(struct Array *arr, int index, int item)
{
    if (index > 0 && index < arr->length)
    {
        arr->A[index] = item;
        return index;
    }
    return -1;
}

/* Get the minimum element in an array */
int Min(struct Array *arr)
{
    int minimum = arr->A[0];
    for (int i = 0; i < arr->length; i++)
        if (arr->A[i] < minimum) minimum = arr->A[i];
    return minimum;
}

/* Get the maximum element in an array */
int Max(struct Array *arr)
{
    int maximum = arr->A[0];
    for (int i = 0; i < arr->length; i++)
        if (arr->A[i] > maximum) maximum = arr->A[i];
    return maximum;
}

/* Returns the sum of all elements in an array */
int Sum(struct Array *arr)
{
    int total = 0;
    for (int i = 0; i < arr->length; i++)
        total += arr->A[i];
    return total;
}

/* Returns the average of an array */
float Average(struct Array *arr)
{
    return (float) Sum(arr) / arr->length;
}

/* Reverse array in place */
void Reverse(struct Array *arr)
{
    for (int i = 0, j = arr->length-1; i < j; i++, j--)
        Swap(arr, i, j);
}

int main()
{
    // Create an array structure
    struct Array arr = 
    {
        {1, 23, 35, 4, 75, 6, 7, 98, 9}, // initialize values
        10,              // set size
        9                // set length
    };
    Display(&arr);
    printf("Search for %d: %d\n", 7, IterativeBinarySearch(&arr, 7));
    printf("Search for %d: %d\n", 3, RecursiveBinarySearch(&arr, 0, 9, 3));
    printf("Search for %d: %d\n", 89, IterativeBinarySearch(&arr, 89));
    printf("Search for %d: %d\n", -14, RecursiveBinarySearch(&arr, 0, 9, -14));
    printf("Element at index: %d is %d\n", 2, Get(&arr, 2));
    printf("Setting element at index: %d to %d\n", 2, 100);
    Set(&arr, 2, 100);
    Display(&arr);
    printf("Sum of array: %d\n", Sum(&arr));
    printf("Average of array: %f\n", Average(&arr));
    printf("Maximum item: %d\n", Max(&arr));
    printf("Minimum item: %d\n", Min(&arr));
    printf("Reversing array....\n");
    Reverse(&arr);
    Display(&arr);
}