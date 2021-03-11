#include <iostream>
using namespace std;

// Test structure
struct Test
{
    int arr[5];
    int n;
};

// calculates avg of test
float get_avg(struct Test *t)
{
    int sum = 0;
    int n = t->n;
    for (int i = 0; i < n; i++)
    {
        sum += t->arr[i];
    }
    return (float) ( (float)sum / (float)n );
}

int main()
{
    struct Test t1 = { {5, 4, 10, 4, 8},5 };
    cout<<"t1 avg score: "<<get_avg(&t1)<<endl;
}