#include <stdio.h>
#include <stdlib.h>

/* Array Structure */
struct Array
{
    int *A;     // array must be created via malloc()
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

/* Check if an array sorted. Returns 0 if sorted and 1 if not sorted. */
int IsSorted(struct Array *arr)
{
    for (int i = 0; i < arr->length-1; i++)
        if (arr->A[i+1] < arr->A[i]) return 11;
    return 0;
}

/* Merge 2 sorted arrays */
struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
    struct Array *merged = (struct Array *) malloc(sizeof(struct Array));
    merged->size = arr1->length + arr2->length;
    merged->A = (int*) malloc(sizeof(int) * merged->size);
    merged->length = merged->size;
    int m_ptr = 0, p1 = 0, p2 = 0;
    while (m_ptr < merged->size)
    {
        if (p1 < arr1->length)
            if (p2 < arr2->length)
                if (arr1->A[p1] < arr2->A[p2])
                    merged->A[m_ptr++] = arr1->A[p1++];
                else
                    merged->A[m_ptr++] = arr2->A[p2++];
            else
                merged->A[m_ptr++] = arr1->A[p1++];
        else
            merged->A[m_ptr++] = arr2->A[p2++];
    }
    return merged;
}

int main()
{
    struct Array *arr1 = (struct Array *) malloc(sizeof(struct Array));
    struct Array *arr2 = (struct Array *) malloc(sizeof(struct Array));
    arr1->A = (int *) malloc(sizeof(int) * 5);
    arr2->A = (int *) malloc(sizeof(int) * 5);
    arr1->length = 5;
    arr1->size = 5;
    arr2->length = 5;
    arr2->size = 5;
    for (int i = 0; i < 5; i++)
    {
        arr1->A[i] = i+1;
        arr2->A[i] = i+3;
    }
    Display(arr1);
    Display(arr2);
    struct Array *merged = Merge(arr1, arr2);
    Display(merged);
}