#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int *pointer;       // declare a pointer variable
    int *pointer2;      // decalare another pointer variable

    /* allocate enough memory for 10 integers in heap memory */
    pointer = (int *) malloc(10 * sizeof(int));  // C style
    pointer2 = new int[10];                      // C++ style

    // Print out values for each index in memory
    for (int i = 0; i < 10; i++)
    {
        cout<<"C style val: "<<pointer[i]<<endl;
        cout<<"C++ style val: "<<pointer2[i]<<endl;
    }

    // Free up memory when done
    free(pointer);      // C
    delete [] pointer2; // C++
}