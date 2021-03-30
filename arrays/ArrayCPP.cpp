#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int length;
    int size;
    void Swap(int i, int j);
public:
    Array() // Default constructor
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array()
    {
        delete []A;
    }
    /* METHODS */
    void Display();
    void Append(int item);
    void Insert(int index, int item);
    int Delete(int index);
    int LinearSearch(int item);
    int IterativeBinarySearch(int target);
    int RecursiveBinarySearch(int lo, int hi, int target);
    int Get(int index);
    int Set(int index, int item);
    int Min();
    int Max();
    int Sum();
    float Average();
    void Reverse();
    int IsSorted();
    Array* Merge(Array *arr);
    Array* UnionSorted(Array *arr);
    Array* IntersectionSorted(Array *arr);
    Array* DifferenceSorted(Array *arr);
    int GetLength();
    void SetLength(int new_length);
    int* GetArray();
};

/* Print Array in std output */
void Array::Display()
{
    cout<<"[";
    for (int i = 0; i < length; i++)
    {
        if (i == length - 1) { cout<<A[i]<<"]"<<endl; break; }
        cout<<A[i]<<", ";
    }
}

/* Add item to end of array */
void Array::Append(int item) // O(1)
{
    if (length < size)      // first check if array is full
        A[length++] = item; // add item to the end
}

/* Insert an item at a given index */
void Array::Insert(int index, int item) // O(N)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length; i > index; --i)
            A[i] = A[i-1];
        A[index] = item;
        length++;
    }
}

/* Delete an item at a given index */
int Array::Delete(int index) // O(N)
{
    int output = 0;
    if (index >= 0 && index <= length)
    {
        output = A[index];
        for (int i = index; i < length-1; i++)
            A[i] = A[i+1];
        length--;
    }
    return output;
}

/* Swap two array elements */
void Array::Swap(int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

/* Returns 0 (index of item) if found item or -1 if not found */
int Array::LinearSearch(int item) // O(N)
{
    for (int i = 0; i < length; i++)
        if (A[i] == item)
        {
            Swap(i, 0); // optimize for future searches
            return 0;
        } 
    return -1;
}

/* Returns index of item if found or -1 if not found. !! Array must be sorted !! */
int Array::IterativeBinarySearch(int target) // O(logN)
{
    int lo = 0;
    int hi = length;
    int mid;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (A[mid] == target)
            return mid;
        else if (A[mid] > target)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return -1;
}

/* Returns index of item if found or -1 if not found. !! Array must be sorted !! */
int Array::RecursiveBinarySearch(int lo, int hi, int target)
{
    if (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (A[mid] == target)
            return mid;
        else if (A[mid] > target)
            return RecursiveBinarySearch(lo, mid-1, target);
        else
            return RecursiveBinarySearch(mid+1, hi, target);
    }
    return -1;
}

/* Returns element at given index or -1 if given index is not valid or element is not found */
int Array::Get(int index)
{
    if (index > 0 && index < length) return A[index];
    return -1;
}

/* Replaces element at given index. Returns index if successful or -1 if not */
int Array::Set(int index, int item)
{
    if (index > 0 && index < length)
    {
        A[index] = item;
        return index;
    }
    return -1;
}

/* Get the minimum element in an array */
int Array::Min()
{
    int minimum = A[0];
    for (int i = 0; i < length; i++)
        if (A[i] < minimum) minimum = A[i];
    return minimum;
}

/* Get the maximum element in an array */
int Array::Max()
{
    int maximum = A[0];
    for (int i = 0; i < length; i++)
        if (A[i] > maximum) maximum = A[i];
    return maximum;
}

/* Returns the sum of all elements in an array */
int Array::Sum()
{
    int total = 0;
    for (int i = 0; i < length; i++)
        total += A[i];
    return total;
}

/* Returns the average of an array */
float Array::Average()
{
    return (float) Sum() / length;
}

/* Reverse array in place */
void Array::Reverse()
{
    for (int i = 0, j = length-1; i < j; i++, j--)
        Swap(i, j);
}

/* Check if an array sorted. Returns 0 if sorted and 1 if not sorted. */
int Array::IsSorted()
{
    for (int i = 0; i < length-1; i++)
        if (A[i+1] < A[i]) return 11;
    return 0;
}

/* Merge 2 sorted arrays */
Array* Array::Merge(Array *arr2)
{
    Array *merged = new Array(length + arr2->GetLength());
    int m_ptr = 0, p1 = 0, p2 = 0;
    while (m_ptr < merged->size)
    {
        if (p1 < length)
            if (p2 < arr2->length)
                if (A[p1] < arr2->A[p2])
                    merged->A[m_ptr++] = A[p1++];
                else
                    merged->A[m_ptr++] = arr2->A[p2++];
            else
                merged->A[m_ptr++] = A[p1++];
        else
            merged->A[m_ptr++] = arr2->A[p2++];
    }
    return merged;
}

int Array::GetLength()
{
    return length;
}

void Array::SetLength(int new_length)
{
    length = new_length;
}

int* Array::GetArray()
{
    return A;
}

/* SET OPERATIONS */

/* Union on two sorted sets */
Array* Array::UnionSorted(Array *arr2)
{
    Array *union_arr = new Array(length + arr2->GetLength());
    int u_ptr = 0, p1 = 0, p2 = 0;
    while (p1 < length || p2 < arr2->length)
    {
        if (p1 < length)
            if (p2 < arr2->GetLength())
                if (A[p1] < arr2->GetArray()[p2])
                    union_arr->GetArray()[u_ptr++] = A[p1++];
                else if (A[p1] > arr2->GetArray()[p2])
                    union_arr->GetArray()[u_ptr++] = arr2->GetArray()[p2++];
                else
                {   // elements are equal
                    union_arr->GetArray()[u_ptr++] = A[p1++];
                    p2++;
                }
            else
                union_arr->GetArray()[u_ptr++] = A[p1++];
        else
            union_arr->GetArray()[u_ptr++] = arr2->GetArray()[p2++];
    }
    union_arr->SetLength(u_ptr);
    return union_arr;
}

/* Intersection (all elements common to both) of two sorted sets */
Array* Array::IntersectionSorted(Array *arr2)
{
    Array *intersection_arr = new Array(length + arr2->GetLength());
    int int_ptr = 0, p1 = 0, p2 = 0;
    while (p1 < length || p2 < arr2->GetLength())
    {
        if (p1 < length)
            if (p2 < arr2->GetLength())
                if (A[p1] < arr2->GetArray()[p2])
                    p1++;
                else if (A[p1] > arr2->GetArray()[p2])
                    p2++;
                else
                {   // elements are equal
                    intersection_arr->GetArray()[int_ptr++] = A[p1++];
                    p2++;
                }
            else 
                break;
        else
            break;
    }
    intersection_arr->SetLength(int_ptr);
    return intersection_arr;
}

/* Difference (all elements unique to arr1) of two sets  */
Array* Array::DifferenceSorted(Array *arr2)
{
    Array *difference_arr = new Array(length + arr2->GetLength());
    int dif_ptr = 0, p1 = 0, p2 = 0;
    while (p1 < length || p2 < arr2->GetLength())
    {
        if (p1 < length)
            if (p2 < arr2->GetLength())
                if (A[p1] < arr2->GetArray()[p2])
                    difference_arr->GetArray()[dif_ptr++] = A[p1++];
                else if (A[p1] > arr2->GetArray()[p2])
                    p2++;
                else
                {   // elements are equal
                    p1++;
                    p2++;
                }
            else 
                difference_arr->GetArray()[dif_ptr++] = A[p1++];
        else
            break;
    }
    difference_arr->SetLength(dif_ptr);
    return difference_arr;
}
