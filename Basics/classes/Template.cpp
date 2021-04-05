#include <iostream>
using namespace std;

template <class T>
class Rectangle
{
    private:
        int id;
        T width;
        T height;
    
    public:
        /* Constructors */
        Rectangle()
        {
            id = 0;
            width = 0;
            height = 0;
        }
        Rectangle(int id, T w, T h)
        {
            this->id = id;
            width = w;
            height = h;
        }
        /* Methods */
        T area()
        {
            return width * height;
        }
        T perimeter()
        {
            return 2 * (width + height);
        }
        /* Destructor */
        ~Rectangle() 
        {
            cout<<"Object destructoring id: "<<id<<endl;
        }
};

int main()
{
    Rectangle<int> r1(100, 10, 20);  // create on stack
    Rectangle<float> *r2 = new Rectangle<float>(200, 20.2, 35.5); // create on heap
    cout<<"r1 Area: "<<r1.area()<<endl;
    cout<<"r1 Perimeter: "<<r1.perimeter()<<endl;
    cout<<"r2 Area: "<<r2->area()<<endl;
    cout<<"r2 Perimeter: "<<r2->perimeter()<<endl;
    r2->~Rectangle(); // 'new' created objects must be manually destructored or deleted
}
