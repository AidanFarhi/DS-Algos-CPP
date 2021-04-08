#include <iostream>
using namespace std;

class LowTriMat
{
    private:
        int *A;
        int n;
    public:
        /* Constructor */
        LowTriMat(int size)
        {
            A = new int[size*(size+1)/2];
            n = size;
        }
        /* Method Declarations */
        void set(int r, int c, int el);
        int get(int r, int c);
        void display();
        void populate();
        /* Destructor */
        ~LowTriMat(){ delete []A; }
};

/* Method Definitions */

/* Sets item at given row and col. (indexes start at 1) */
void LowTriMat::set(int r, int c, int el)
{
    if (r >= c && r >= 0 && c >= 0 && el >= 0)
        A[r*(r-1)/2 + c-1] = el;
}

/* Gets item at given row and col. (indexes start at 1) */
int LowTriMat::get(int r, int c)
{
    if (r >= c && r >= 0 && c >= 0)
        return A[r*(r-1)/2 + c-1];
    return 0;
}

/* Displays Matrix */
void LowTriMat::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (i >= j)
                cout << get(i, j) << " ";
            else    
                cout << "0 ";
        cout << endl;
    }
}

/* Popluates lower triangle with 1's */
void LowTriMat::populate()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i >= j)
                set(i, j, 1);
}

int main()
{
    int sz;
    cout << "Enter size of matrix: ";
    cin >> sz;
    LowTriMat *mat = new LowTriMat(sz);
    mat->populate();
    mat->display();
    mat->~LowTriMat();
}