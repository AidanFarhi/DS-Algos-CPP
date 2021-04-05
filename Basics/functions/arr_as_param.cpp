#include <iostream>
using namespace std;

// arrays are always passed by adress
void show_items(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1) { cout<<arr[i]; break; }
        cout<<arr[i]<<"->";
    }
    cout<<endl;
}

// add 10 to all items in array
void change_items(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] + 10;
    }
}

int main()
{
    int my_array[7] = {1, 2, 3, 4, 5, 6, 7};
    change_items(my_array, 7);
    show_items(my_array, 7);
}