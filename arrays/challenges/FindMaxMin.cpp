#include <iostream>
using namespace std;

int* min_max(int *arr, int len)
{
    int *output = new int[2];
    output[0] = arr[0];  // min
    output[1] = arr[0];  // max
    for (int i = 0; i < len; i++)
    {
        output[0] = min(arr[i], output[0]);
        output[1] = max(arr[i], output[1]);
    }
    return output;
}

int main()
{
    int test[14] = {5, 1, -55, 6, -111, 6, 2, 7, 636, 2, 77777, 2, 5, -266666};
    int *result = min_max(test, 14);
    cout << "Min: " << result[0] << " Max: " << result[1] << endl;
}