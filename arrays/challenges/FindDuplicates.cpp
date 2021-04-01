#include <iostream>
#include <vector>
using namespace std;

vector<int>* find_duplicates(int *arr, int len)
{
    vector<int> *duplicates = new vector<int>;
    bool found_duplicate = false;
    int last_duplicate_found = 0;
    for (int i = 0; i < len-1; i++)
    {
        if (arr[i] == arr[i+1]) // we have a duplicate
        {
            if (found_duplicate == false)  // this is the first duplicate we have seen
            {
                found_duplicate = true;
                last_duplicate_found = arr[i];
                duplicates->push_back(arr[i]);
            }
            else  // we have seen a duplicate already
            {
                if (last_duplicate_found != arr[i])  // we only want one copy of each duplicate
                {
                    last_duplicate_found = arr[i];
                    duplicates->push_back(arr[i]);
                }
            }
        }
    }
    return duplicates;
}


int main()
{
    int test[19] = {-34, -31, -31, -5, -5, -1, 0, 0, 0, 1, 1, 6, 7, 88, 88, 200, 244, 555, 555};
    vector<int> *duplicates = find_duplicates(test, 19);
    int *arr = duplicates->data();
    int n = duplicates->size();
    cout << "Duplicates: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}