#include <iostream>
using namespace std;

void tree_recursion(int n)
{
    if (n > 0)
    {
        cout<<n<<" ";
        tree_recursion(n - 1);
        tree_recursion(n - 1);
    }
}

int main()
{
    tree_recursion(3);
}