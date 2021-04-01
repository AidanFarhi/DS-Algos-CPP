#include <iostream>
#include <vector>
using namespace std;

vector<int>* find_duplicates_sorted(int *arr, int len)
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

void show_vector(vector<int>* v)
{
    int *arr = v->data();
    int n = v->size();
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        if (i == n-1) { cout << arr[i] << "]" << endl; break; }
        cout << arr[i] << ", ";
    }
}

int main()
{
    int sorted[20] = {-34, -31, -31, -5, -5, -1, 0, 0, 0, 1, 1, 6, 7, 88, 88, 200, 200, 244, 555, 555};
    int unsorted[20] = {4, 1, 6, 2, -11, -11, 7, 2, 5, 4, 55, 55, -2, -22, -22, 788, 266, 3, 3, 3};
    vector<int> *duplicates = find_duplicates_sorted(sorted, 20);
    show_vector(duplicates);
}