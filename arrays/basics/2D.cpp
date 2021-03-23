#include <iostream>
#include <stdlib.h>
using namespace std;

void show_items(int **arr)
{
    for (int i = 0; i < 3; i++)
    {
        cout<<"[";
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                cout<<arr[i][j];
                break;
            }
            cout<<arr[i][j]<<", ";
        }
        cout<<"]"<<endl;
    }
}

int main()
{
    /* 2D array created in STACK | C and C++ */
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};  // in STACK

    /* Array of POINTERS created in STACK, each POINTER points to an array in HEAP | C style */
    int *B_C[3];                             // in STACK
    B_C[0] = (int*) malloc(sizeof(int) * 3); // in HEAP
    B_C[1] = (int*) malloc(sizeof(int) * 3); // in HEAP
    B_C[2] = (int*) malloc(sizeof(int) * 3); // in HEAP

    /* Array of POINTERS created in STACK, each POINTER points to an array in HEAP | C++ style */
    int *B_CPP[3];         // in STACK
    B_CPP[0] = new int[3]; // in HEAP
    B_CPP[1] = new int[3]; // in HEAP
    B_CPP[2] = new int[3]; // in HEAP

    /* Array of POINTERS created in HEAP, each POINTER points to an array in HEAP | C */
    int **C_C = (int**) malloc(sizeof(int *) * 3); // in HEAP
    C_C[0] = (int*) malloc(sizeof(int) * 3);       // in HEAP
    C_C[1] = (int*) malloc(sizeof(int) * 3);       // in HEAP
    C_C[2] = (int*) malloc(sizeof(int) * 3);       // in HEAP

    /* Array of POINTERS created in HEAP, each POINTER points to an array in HEAP | C++ */
    int **C_CPP = new int*[3];  // in HEAP
    C_CPP[0] = new int[3];      // in HEAP
    C_CPP[1] = new int[3];      // in HEAP
    C_CPP[2] = new int[3];      // in HEAP

    // Now lets set each value of each array (Excluding first array)
    int num = 1;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            B_C[i][j] = num;
            B_CPP[i][j] = num;
            C_C[i][j] = num;
            C_CPP[i][j] = num;
            num++;
        }
    }

    // Now lets print out each array
    cout<<"--------------"<<endl;
    show_items(B_C);
    cout<<"--------------"<<endl;
    show_items(B_CPP);
    cout<<"--------------"<<endl;
    show_items(C_C);
    cout<<"--------------"<<endl;
    show_items(C_CPP);
}