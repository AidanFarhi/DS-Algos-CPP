#include <iostream>
using namespace std;

// makes an int array of size n C style
int* make_arr_C(int n)
{   // C style array creation
    return (int *) malloc(sizeof(int) * n); 
}

// makes an int array of size n C++ style
int* make_arr_Cpp(int n)
{
    return new int[n];
}

int main()
{
    int *arr = make_arr_C(10);
    int *arr2 = make_arr_Cpp(5);

    // print out C style arr
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<", ";
    }
    cout<<endl;

    // print out C++ style arr
    for (int i = 0; i < 5; i++)
    {
        cout<<arr2[i]<<", ";
    }
    cout<<endl;

    // free up memory
    free(arr);   // for C
    delete arr2; // for C++
}