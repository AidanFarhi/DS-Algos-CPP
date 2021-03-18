#include <iostream>
using namespace std;

/* Return the sum of all natural numbers from 1 to N */

/* Recursive Solution */
int nat_nums_recursive(int n)
{
    if (n == 1) // base case
        return 1;
    return nat_nums_recursive(n - 1) + n;
}

/* Iterative Solution */
int nat_nums_iterative(int n)
{
    int result = 1;
    for (int i = 2; i <= n; i++)
        result += i;
    return result;
}

/* Mathematical Solution */
int nat_nums_math(int n)
{
    return n * (n + 1) / 2;
}

int main()
{
    int test = 5;
    int recursive_result = nat_nums_recursive(test);
    int iterative_result = nat_nums_iterative(test);
    int math_result = nat_nums_math(test);
    cout<<"Math Result: "<<math_result<<endl;
    cout<<"Recursive Result: "<<recursive_result<<endl;
    cout<<"Iterative Result: "<<iterative_result<<endl;
}