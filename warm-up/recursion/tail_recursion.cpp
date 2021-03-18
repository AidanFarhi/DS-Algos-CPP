#include <iostream>
using namespace std;

void tail_recursion(int n)
{
    if (n > 0)
    {
        // Work is done first
        cout<<n<<" ";
        // Then recursion is performed
        tail_recursion(n - 1);
    }
}

int main()
{
    int test = 5;
    tail_recursion(test);
}