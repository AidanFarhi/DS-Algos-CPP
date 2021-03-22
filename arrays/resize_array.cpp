#include <iostream>
using namespace std;

int main()
{
    // initialize and set vals in an array on heap
    int *arr = new int[5];
    arr[0] = 1; 
    arr[1] = 3; 
    arr[2] = 5;
    arr[3] = 7;
    arr[4] = 9;

    // now check values
    for (int i = 0; i < 5; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    // now create an new arr of double size and copy elements into new array
    int *new_arr = new int[10];
    for (int i = 0; i < 5; i++)
        new_arr[i] = arr[i];

    // now clean up memory
    delete [] arr;
    arr = new_arr;
    new_arr = NULL;

    // make sure it worked
    for (int i = 0; i < 10; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}