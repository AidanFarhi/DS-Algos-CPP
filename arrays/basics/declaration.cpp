#include <iostream>
using namespace std;

int main()
{
    int a1[5];                      // will fill array with garbage values
    int a2[5] = {1, 2, 3, 4, 5};    // will initialize all elements
    int a3[5] = {1, 2};             // will fill first two elements, and rest will be 0's
    int a4[5] = {0};                // will fill with 0's
    int a5[] = {1, 2, 3, 4, 5, 6};  // will fill array with elements given and initilaze size
}