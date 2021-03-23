#include <iostream>
using namespace std;

int main()
{
    int a[5] = {1,2,3,4,5}; // initialize array with size 5

    // Using traditional for loop
    for (int i = 0; i < 5; i++)
        cout<< a[i] <<" ";
    cout<<endl;

    // Using for loop with alternate identifier
    for (int i = 0; i < 5; i++)
        cout<< i[a] <<" ";
    cout<<endl;

    // Using for loop and pointer arithmatic
    for (int i = 0; i < 5; i++)
        cout<< *(a + i) <<" ";
    cout<<endl;

    // Print out adresses
    for (int i = 0; i < 5; i++)
        cout<< &a[i] <<" ";
    cout<<endl;
}