#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int width;
};

void intialize(struct Rectangle *r, int l, int w)
{
    r->length = l;
    r->width = w;
}

int area(struct Rectangle *r)
{
    return r->length * r->width;
}

int main()
{
    struct Rectangle *r1 = new Rectangle;
    intialize(r1, 10, 40);
    cout<<"Area: "<<area(r1)<<endl;
    delete r1;
}