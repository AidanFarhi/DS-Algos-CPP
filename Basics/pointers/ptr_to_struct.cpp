#include <iostream>
#include <stdlib.h>
using namespace std;

struct Rectangle
{
    int height;
    int width;
};

int main()
{
    // declare 2 pointers to structures
    struct Rectangle *p1;
    struct Rectangle *p2;

    // C style allocation
    p1 = (struct Rectangle *) malloc(sizeof(struct Rectangle));
    p1->height = 10;
    p1->width = 20;

    // C++ style allocation
    p2 = new Rectangle;
    p2->height = 20;
    p2->width = 40;

    // Print out areas
    cout<<"Area of p1 rectangle: "<<(p1->height*p1->width)<<endl;
    cout<<"Area of p2 rectangle: "<<(p2->height*p2->width)<<endl;

    // Deallocate memory
    free(p1);
    delete p2;
}