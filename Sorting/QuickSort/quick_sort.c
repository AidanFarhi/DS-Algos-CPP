#include <stdio.h>

/* Function Prototypes */
void quick_sort(int *arr, int l, int h);
int partition(int *arr, int l, int h);
void swap(int *arr, int i, int j);
void print_array(int *arr, int n);

void quick_sort(int *arr, int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(arr, l, h);
        quick_sort(arr, l, j);
        quick_sort(arr, j+1, h);
    }
}

int partition(int *arr, int l, int h)
{
    int pivot = arr[l];
    int i = l, j = h;
    do
    {
        do {i++;} while (arr[i] <= pivot);
        do {j--;} while (arr[j] > pivot);
        if (i < j) swap(arr, i, j);
    } while (i < j);
    swap(arr, l, j);
    return j;
}

void swap(int *arr, int i, int j)
{
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

void print_array(int *arr, int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        if (i == n-1) printf("%d", arr[i]);
        else printf("%d, ", arr[i]);
    }
    printf("]\n");
}

int main()
{
    int test[] = {54, 23, -64, 33, 642, -77, 12, 34, -617, 33, __INT_MAX__};
    int n = 11;
    quick_sort(test, 0, n-1);
    print_array(test, n-1);
}