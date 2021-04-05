#include <iostream>
using namespace std;

// a function that takes in two VALUES and swaps the VALUES
void swap(int x, int y)
{
    int temp = x; 
    x = y;       
    y = temp;    
}

int main()
{
    int a = 10, b = 20;
    // this will do nothing because we are passing the VALUE, 
    // not the ADRESS or REFERENCE
    swap(a, b); 
    cout<<"a: "<<a<<" b: "<<b<<endl;
}