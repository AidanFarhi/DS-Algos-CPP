#include <stdio.h>

/* Function Prototypes */
void recursive_merge_sort(int *arr, int l, int h);
void merge(int *arr, int l, int m, int h);
void print_array(int *arr, int n);

/**
 *   --------------
 *   Merge Sort
 *   --------------
 *   - Adaptive
 *   - Stable  
 * 
 *   Time Complexity
 *   ---------------
 *   Worst Case - O(NlogN)
 *   Best Case  - O(NlogN) 
 */

void recursive_merge_sort(int *arr, int l, int h)
{
    if (l < h)
    {
        int m = (l + h) / 2;
        recursive_merge_sort(arr, l, m);
        recursive_merge_sort(arr, m+1, h);
        merge(arr, l, m, h);
    }
}

void merge(int *arr, int l, int m, int h)
{
    int i = l, j = m+1, k = l;
    int aux[100];
    while (i <= m && j <= h)
    {
        if (arr[i] < arr[j])
            aux[k++] = arr[i++];
        else
            aux[k++] = arr[j++];
    }
    // Merge remaining elements
    for (; i <= m; i++)
        aux[k++] = arr[i];
    for (; j <= h; j++)
        aux[k++] = arr[j];
    // Now copy aux into original array
    for (int p = l; p <= h; p++)
        arr[p] = aux[p];
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
    recursive_merge_sort(test1, 0, 7);
    recursive_merge_sort(test2, 0, 16);
    print_array(test1, 8);
    print_array(test2, 17);
}