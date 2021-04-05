#include <iostream>
using namespace std;

// A rectangle object
struct Rectangle
{
    int height;
    int width;
};

// reuturns the area of a Rectangle structure
int area(struct Rectangle *r)
{
    return (r->height * r->width);
}

// checks if structure is a rectangle or not
bool is_rectangle(struct Rectangle *r)
{
    return r->height != r->width ? true : false;
}

int main()
{
    // create two new rectangle structures
    struct Rectangle *r1 = new Rectangle;
    r1->height = 10;
    r1->width = 5;

    struct Rectangle *r2 = new Rectangle;
    r2->height = 10;
    r2->width = 10;

    // print out some checks
    cout<<"area of r1: "<<area(r1)<<endl;
    cout<<"r1 valid rect: (0) false (1) true: "<<is_rectangle(r1)<<endl;
    cout<<"----------"<<endl;
    cout<<"area of r2: "<<area(r2)<<endl;
    cout<<"r2 valid rect: (0) false (1) true: "<<is_rectangle(r2)<<endl;

    // free up memory from heap
    delete r1;
    delete r2;

}