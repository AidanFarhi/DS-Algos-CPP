#include <iostream>
using namespace std;

/* Function prototypes */
int fib_recursive(int n);
int fib_memo(int n);
int fib_memo_helper(int n, int *memo);
int fib_iterative(int n);

/* 
   |--------------------------------------|
   |             0                 n = 0  |
   |           /                          |  
   | fib(n) = {  1                 n = 1  |
   |           \                          |
   |            fib(n-1)+fib(n-2)  n > 1  |
   |                                      |  
   |  - The fibonacci series formula -    |  
   |--------------------------------------|
*/

/* Recursive Solution */
int fib_recursive(int n)
{
    if (n <= 1)
        return n;
    return fib_recursive(n - 2) + fib_recursive(n - 1); 
}

/* Recursive with Memoization */
int fib_memo(int n)
{
    int memo[n];
    for (int i = 0; i < n; i++)
        memo[i] = -1;
    return fib_memo_helper(n, memo);
}
int fib_memo_helper(int n, int *memo)
{
    if (n <= 1)
    {
        memo[n] = n;
        return n;
    }
    else
    {
        // First check if n - 1 or n - 2 has been calculated
        if (memo[n-2] == -1)
            memo[n-2] = fib_memo_helper(n-2, memo);  // set memo[n-2]

        if (memo[n-1] == -1)
            memo[n-1] = fib_memo_helper(n-1, memo);  // set memo[n-1]

        // set nth number
        memo[n] = memo[n-2] + memo[n-1];
        // return result
        return memo[n-2] + memo[n-1];
    }
}

/* Iterative Solution */
int fib_iterative(int n)
{
    if (n <= 1)
        return n;
    int t0 = 0, t1 = 1, s;
    for (int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int main()
{
    int num = 7;
    int fib_rec_result = fib_recursive(num);
    int fib_iterative_result = fib_iterative(num);
    int fib_memo_result = fib_memo(num);
    cout<<"Recursive result: "<<fib_rec_result<<endl;
    cout<<"Iterative result: "<<fib_iterative_result<<endl;
    cout<<"Memo result: "<<fib_memo_result<<endl;
}
