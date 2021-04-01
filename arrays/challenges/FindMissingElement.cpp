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
    /* Method using a hashset. Only works with positive nums, and max num cannot be too large */
    static vector<int>* hash_method(int *arr, int len)
    {
        vector<int> *missing = new vector<int>;
        // first find max item
        int maximum = arr[0];
        for (int i = 0; i < len; i++)
            maximum = max(maximum, arr[i]);
        // create an array of maximum element size
        int hash[maximum+1];
        // populate hash array
        for (int i = 0; i < len; i++)
            hash[arr[i]] = 1;
        // now find the missing elements of the hash array
        for (int i = 1; i <= maximum; i++)
            if (hash[i] != 1)
                missing->push_back(i);
        return missing;
    }
};

int main()
{
    int test[] = {1,2,3,4,5,6,8,10,13,16,19,22};
    vector<int> *missing = FindMissingElement::hash_method(test, 12);
    int *res = missing->data();
    int len = missing->size();
    cout << "Missing elements: ";
    for (int i = 0; i < len; i++)
        cout << res[i] << " ";
    cout << endl;
}