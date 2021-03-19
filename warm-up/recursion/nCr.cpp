#include <iostream>
using namespace std;

/* 

The nCr formula is used to find the amount of combinations
you can get from n items choosing r at a time.

ex) ['A', 'B', 'C'] -> 3(n) (C)choose 2(r) -> ['A', 'B'], ['A', 'C'], ['B', 'C']

Formula: nCr = n! / (n – r)! * r!

*/

/* Function Prototypes */
int factorial(int n);
int nCr_fact(int n, int r);

/* function for finding factorial of a number */
int factorial(int n)
{
    if (n == 0)
        return 1;
    return factorial(n-1) * n;
}

/* solution using factorials */
int nCr_fact(int n, int r)
{
    int num, den;
    num = factorial(n);
    den = factorial(r) * factorial(n-r);
    return num / den;
}

/* Recursive Solution */
int nCr_recursive(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    return nCr_recursive(n - 1, r - 1) + nCr_recursive(n - 1, r);
}

int main()
{
    cout<<"Factorial Solution: "<<nCr_fact(5, 2)<<endl;
    cout<<"Recursive Solution: "<<nCr_recursive(5, 2)<<endl;
}