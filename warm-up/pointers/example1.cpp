#include <iostream>
using namespace std;

int main()
{
    int data = 100;     // create a variable
    int *pointer;       // create a pointer
    pointer = &data;    // assign adress of data to pointer
    
    /* The different ways to access data */
    cout<<"adress of data variable: "<<&data<<endl;
    cout<<"value stored in pointer variable: "<<pointer<<endl;
    cout<<"access data value using variable: "<<data<<endl;
    cout<<"access data value using pointer derefrencing: "<<*pointer<<endl;
}