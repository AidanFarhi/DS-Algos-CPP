#include <iostream>
using namespace std;

/* Recursive Solution */
int factorial_recursive(int n)
{
    if (n == 0)
        return 1;
    return factorial_recursive(n - 1) * n;
}

/* Iterative Solution */
int factorial_iterative(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}

int main()
{
    int recursive_result = factorial_recursive(5);
    int iterative_result = factorial_iterative(5);
    cout<<"Recursive result: "<<recursive_result<<endl;
    cout<<"Iterative result: "<<iterative_result<<endl;
}