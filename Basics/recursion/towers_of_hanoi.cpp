#include <stdio.h>
using namespace std;

/* Towers of Hanoi problem */

/* disks: # of disks | A: source twr | B: aux twr | C: destination twr */
void TOH(int disks, int A, int B, int C)
{
    if (disks > 0)
    {
        TOH(disks - 1, A, C, B);
        printf("From %d -> %d\n", A, C);
        TOH(disks - 1, B, A, C);
    }
}

int main()
{
    TOH(3, 1, 2, 3);
}