#include <iostream>
using namespace std;

void head_recursion(int n)
{
    if (n > 0)
    {
        // First recursion is performed
        head_recursion(n - 1);
        // Then work is done
        cout<<n<<" ";
    }
}

int main()
{
    int test = 5;
    head_recursion(test);
}