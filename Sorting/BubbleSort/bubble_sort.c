#include <stdio.h>

/* Function Prototypes */
void bubble_sort(int *arr, int n);
void swap(int *arr, int i, int j);
void print_array(int *arr, int n);

/**
 *   -----------
 *   Bubble Sort
 *   -----------
 * 
 * - Adaptive (if you introduce an is_sorted flag)
 * - Comparison Based
 * - Stable
 * 
 *   Time Complexity
 *   ---------------
 *   Worst Case - O(N^2)
 *   Best Case  - O(N)
 */

void bubble_sort(int *arr, int n)
{
    int is_sorted;
    for (int i = 0; i < n - 1; i++)
    {
        is_sorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr, j, j+1);
                is_sorted = 0;
            }
        }
        if (is_sorted) { printf("Array is sorted. Passes: %d\n", i+1); break; }
    }
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
    int test1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int test2[] = {54, 2, -55, 22, 646, 2, 665, 76, 144, 7, 445, -22, -661, -6, 63, 43, 222};
    bubble_sort(test1, 8);
    bubble_sort(test2, 17);
    print_array(test1, 8);
    print_array(test2, 17);
}