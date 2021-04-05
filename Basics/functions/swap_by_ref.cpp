#include <iostream>
using namespace std;

// here we are passing in REFERENCES to x and y not pointers
// this is a C++ feature
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 100, b = 200;
    swap(a, b);  // this works because we pass by REFERENCE
    cout<<"a: "<<a<<" b: "<<b<<endl;
}