#include <iostream>
#include <list>
#include <vector>
using namespace std;

void bin_sort(int *arr, int n)
{
    // First find max element
    int max_el = arr[0];
    int i, j = 0;
    for (i = 1; i < n; i++)
        if (max_el < arr[i]) max_el = arr[i];
    // Now make an array of Lists the size of max element + 1
    vector<list<int>*> *bins = new vector<list<int>*>(max_el + 1);
    for (i = 0; i < max_el + 1; i++)
        bins->at(i) = new list<int>;
    // Put each item of arr into its bucket
    for (i = 0; i < n; i++)
        bins->at(arr[i])->push_front(arr[i]);
    // Now insert each element back into original array
    for (i = 0; i < max_el + 1; i++)
    {
        while (!bins->at(i)->empty())
        {
            arr[j++] = bins->at(i)->front();
            bins->at(i)->pop_front();
        }
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
    int test[] = {1, 4, 2, 5, 2, 3, 7, 12, 23, 22, 15, 16, 11, 27, 2, 3, 4};
    bin_sort(test, 17);
    print_array(test, 17);
}