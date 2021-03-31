#include <iostream>
#include <vector>
using namespace std;

/*
Challenge: Find the missing element(s) in sorted array
Ex): [1, 2, 3, 4, 6, 7, 8] -> 5
*/

class FindMissingElement
{
    public:
    /* 
    This methods uses the n(n+1)/2 formula to find the ONE missing element.
    This will only work if there is ONE element missing.
    Array must be sorted.
    */
    static int formula_method(int *arr, int len)
    {
        int n = arr[len-1];      // get largest number (n)
        int sum = n * (n+1) / 2; // formula for sum of first n natural nums
        int total = 0;
        for (int i = 0; i < len; i++)
            total += arr[i];
        return sum - total;
    }
    /* 
    This method uses the indexes of the array and calculates the difference.
    This method will find ALL missing elements.
    Array must be sorted.
    */
    static vector<int>* index_method(int *arr, int len)
    {
        int diff = arr[0];
        vector<int> *missing = new vector<int>;
        for (int i = 0; i < len; i++)
            if (arr[i]-i != diff)
            {
                while (diff < arr[i]-i)
                {
                    missing->push_back(diff+i);
                    diff++;
                }
            }
        return missing; // will return vector of mising elements
    }
};

int main()
{
    int test[] = {1,2,3,4,5,6,8,10,13};
    vector<int> *missing = FindMissingElement::index_method(test, 9);
    int *res = missing->data();
    int len = missing->size();
    cout << "Missing elements: ";
    for (int i = 0; i < len; i++)
        cout << res[i] << " ";
    cout << endl;
}