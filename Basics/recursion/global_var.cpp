#include <iostream>
using namespace std;

int x = 0;

int global_var(int n)
{
    if (n > 0)
    {
        x++;
        return global_var(n - 1) + x;
    }
    return 0;
}

int main()
{
    int test = 5;
    int result = global_var(test);
    cout<<result<<endl;
}