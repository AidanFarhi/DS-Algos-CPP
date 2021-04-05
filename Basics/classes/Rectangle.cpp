#include <iostream>
using namespace std;

class Rectangle
{
    private:
        int length;
        int width;

    public:
        /* Constructors */
        Rectangle()  // Default
        {
            length = 0;
            width = 0;
        }
        Rectangle(int l, int w)  // Parameterized constructor
        {
            length = l;
            width = w;
        }
        /* Methods */
        int area()
        {
            return length * width;
        }
        int perimeter()
        {
            return 2 * (length * width);
        }
        /* Destructor */
        ~Rectangle() 
        { 
            cout<<"Destroying Object"<<endl; 
        }
};

int main()
{
    Rectangle r(10, 50); // create a rectangle object
    cout<<"Area: "<<r.area()<<endl;
    cout<<"Perimeter: "<<r.perimeter()<<endl;
    return 0;
}