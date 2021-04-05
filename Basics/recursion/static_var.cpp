#include <iostream>
using namespace std;

int static_var(int n)
{
    // This is shared across all function calls
    static int x = 0;
    if (n > 0)
    {
        x++;
        return static_var(n - 1) + x;
    }
    return 0;
}

int main()
{
    int test = 5;
    int result = static_var(test);
    cout<<result<<endl;
}