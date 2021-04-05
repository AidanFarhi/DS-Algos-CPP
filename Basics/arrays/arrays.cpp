#include <iostream>

using namespace std;

int main()
{
    // Take in input from user for size of array,
    // then populate array and print elements
    int N;
    cout<<"Enter size of array:";
    cin>>N;
    int A[N];
    for (int i = 0; i < N; i++)
    {
        A[i] = i;
    }
    // C++ supports for each loops
    for (int n: A)
    {
        cout<<n<<endl;
    }
}