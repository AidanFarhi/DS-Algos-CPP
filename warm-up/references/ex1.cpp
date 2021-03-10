#include <iostream>
using namespace std;

int main()
{
    int a = 100;  
    int &ref = a; // this is a reference to a
    int ref2 = a; // this is a new variable with same value as a

    // increment all variables
    a++;
    ref++;
    ref2++;

    cout<<a<<endl;
    cout<<ref<<endl;
    cout<<ref2<<endl;

    cout<<"adress of a: "<<&a<<endl;
    cout<<"adress of ref: "<<&ref<<endl;
    cout<<"adress of ref2: "<<&ref2<<endl;
}