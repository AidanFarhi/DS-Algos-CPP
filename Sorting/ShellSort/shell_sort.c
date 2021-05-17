#include <stdio.h>

void shell_sort(int *arr, int n)
{
    int gap, i, j, temp;
    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = arr[i];
            j = i - gap;
            while (j >= 0 && arr[j] > temp)
            {
                arr[j+gap] = arr[j];
                j = j - gap;
            }
            arr[j+gap] = temp;
        }
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
    int test[] = {4, -1, 55, 23, 15, -63, 156, 33, 77, 265, -267, 14, -717, 12, -466, 44461, 7};
    shell_sort(test, 17);
    print_array(test, 17);
}