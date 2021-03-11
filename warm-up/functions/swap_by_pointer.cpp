#include <iostream>
using namespace std;

// a function that takes in two POINTERS and swaps the values stored in those POINTERS
void swap(int *x, int *y)
{
    int temp = *x; // dereference to get the value stored in x
    *x = *y;       // put the value of y into x
    *y = temp;     // put the old value of x into y
}

int main()
{
    int a = 10, b = 20;
    // Here we have to pass the address of a and b
    swap(&a, &b);
    cout<<"a: "<<a<<" b: "<<b<<endl;
}