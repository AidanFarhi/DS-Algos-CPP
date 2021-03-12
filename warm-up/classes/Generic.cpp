#include <iostream>
using namespace std;

template <class T>
class Arithametic
{
    private:
        T a;
        T b;
    
    public:
        Arithametic(T a, T b);
        T add();
        T subtract();
};

template <class T>
Arithametic<T>::Arithametic(T a, T b)
{
    this->a = a;
    this->b = b;
}

template <class T>
T Arithametic<T>::add()
{
    return a + b;
}

template <class T>
T Arithametic<T>::subtract()
{
    return a - b;
}

int main()
{
    Arithametic<int> a1(10, 50);
    Arithametic<float> a2(51.6, 15.9);
    cout<<"a1 add: "<<a1.add()<<endl;
    cout<<"a2 add: "<<a2.add()<<endl;
    cout<<"a1 subtract: "<<a1.subtract()<<endl;
    cout<<"a2 subtract: "<<a2.subtract()<<endl;
}