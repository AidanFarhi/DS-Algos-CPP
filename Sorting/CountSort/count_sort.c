#include <stdio.h>

/* Function Prototypes */
void print_array(int *arr, int n);
void count_sort(int *arr, int n);

void count_sort(int *arr, int n)
{
    // First find maximum element of array
    int max_element = arr[0];
    for (int i = 0; i < n; i++)
        if (arr[i] > max_element) max_element = arr[i];
    // Create a counts array
    int counts[max_element + 1];
    for (int i = 0; i < max_element+1; i++)
        counts[i] = 0;
    // Now get a count of each elements
    for (int i = 0; i < n; i++)
        counts[arr[i]] += 1;
    // Now repopulate original array using counts
    int i = 0, j = 0;
    while (i < n)
    {
        if (counts[j] > 0)
        {
            arr[i++] = j;
            counts[j]--;
        } else j++;
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
   int test[] = {5, 4, 6, 1, 2, 1, 6, 7, 7, 14, 11, 13, 13, 1};
   count_sort(test, 14);
   print_array(test, 14);
}