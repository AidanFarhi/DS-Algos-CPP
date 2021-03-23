#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    // This array will be created in stack memory
    int static_arr[5];  

    // C++ style for creating an array in heap memory
    int *dynamic_arr_CPP = new int[5]; 

    // C style for creating an array in heap memory
    int *dynamic_arr_C = (int*) malloc(sizeof(int) * 5); 

    /* Cleanup */
    free(dynamic_arr_C);
    delete []dynamic_arr_CPP;
}