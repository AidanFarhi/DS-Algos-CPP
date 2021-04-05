#include <iostream>
using namespace std;

/* x = power | n = number of terms */
double taylor_series_recursive(int x, int n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
        return 1;
    r = taylor_series_recursive(x, n - 1);
    p = p * x;
    f = f * n;
    return r + p / f;
}   

/* x = power | n = number of terms */
double taylor_series_horners(int x, int n)
{
    static double s;
    if (n == 0)
        return s;
    s = 1 + x * s / n;
    return taylor_series_horners(x, n - 1);
}

/* x = power | n = number of terms */
double taylor_series_iterative(int x, int n)
{
    double s = 1, num = 1, den = 1;
    for (int i = 1; i <= n; i++)
    {
        num *= x;
        den *= i;
        s += num / den;
    }
    return s;
}

int main()
{
    cout<<taylor_series_recursive(1, 10)<<endl;
    cout<<taylor_series_horners(1, 10)<<endl;
    cout<<taylor_series_iterative(1, 10)<<endl;
}