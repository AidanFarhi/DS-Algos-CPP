#include <iostream>
#include <queue>
using namespace std;

void radix_sort(int *arr, int n)
{
    int max_element = arr[0];
    int i;
    for (i = 0; i < n; i++) if (arr[i] > max_element) max_element = arr[i];
    queue<int> bins[10];
    int bin_index, divisor = 1;
    while (divisor < max_element)
    {
        for (i = 0; i < n; i++)
        {
            bin_index = (arr[i] / divisor) % 10;
            bins[bin_index].push(arr[i]);
        }
        int k = 0;
        for (i = 0; i < 10; i++)
        {
            while (!bins[i].empty())
            {
                arr[k++] = bins[i].front();
                bins[i].pop();
            }
        }
        divisor *= 10;
    }
}

void print_array(int *arr, int n)
{
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        if (i == n-1) cout << arr[i];
        else cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}

int main()
{
    int test[30] = {0};
    for (int i = 0; i < 30; i++)
    {
        test[i] = rand() % 9999 + 1;
    }
    radix_sort(test, 30);
    print_array(test, 30);
}