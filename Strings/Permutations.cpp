#include <iostream>
#include <string>
using namespace std;

void permutations(string str, int k) 
{
    static int n = str.length();
    static int *avail = new int[n];
    static char *res = new char[n];
    if (k == n)
    {
        cout << res << endl;
    } else
    {
        for (int i = 0; i < n; i++)
        {
            if (avail[i] == 0)
            {
                avail[i] = 1;
                res[k] = str[i];
                permutations(str, k+1);
                avail[i] = 0;
            }
        }
    }
}

int main()
{
    string test = "ABC";
    permutations(test, 0);
}