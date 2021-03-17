#include <iostream>
using namespace std;

int fun(int n)
{
    static int x = 0;  // this is a shared variable across all recursive calls
    cout<<"value of x: "<<x<<endl;
    if (n > 0)
    {
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}

int main()
{
    int a = 5;
    int res = fun(a);
    cout<<res<<endl;
}