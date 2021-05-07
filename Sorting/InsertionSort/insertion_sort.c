#include <stdio.h>

/* Function Prototypes */
void insertion_sort(int *arr, int n);
void print_array(int *arr, int n);
void swap(int *arr, int i, int j);

/**
 *   --------------
 *   Insertion Sort
 *   --------------
 *   - Adaptive
 *   - Stable  
 * 
 *   Time Complexity
 *   ---------------
 *   Worst Case - O(N^2)
 *   Best Case  - O(N) 
 */

void insertion_sort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > current)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
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
    insertion_sort(test1, 8);
    insertion_sort(test2, 17);
    print_array(test1, 8);
    print_array(test2, 17);
}