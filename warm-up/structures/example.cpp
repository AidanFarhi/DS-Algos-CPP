#include <stdio.h>
#include <iostream>

using namespace std;


/* Define struct here */
struct Triangle
{
    int base;
    int side1;
    int side2;
} t1, t2, t3; // you can initialize variables here too

int main()
{
    // assign values to members
    t1.base = 10;
    t1.side1 = 5;
    t1.side2 = 5;
    cout<<sizeof(t1)<<endl;
}