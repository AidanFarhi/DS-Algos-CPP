#include <iostream>
using namespace std;

class UpperTriMat
{
    private:
        int *A;
        int n;
    public:
        /* Constructor */
        UpperTriMat(int size)
        {
            A = new int[size*(size+1)/2];  // size formula n * (n+1) / 2
            n = size;
        }
        /* Method Declarations */
        void set(int r, int c, int el);
        int get(int r, int c);
        void populate();
        void display();
        /* Destructor */
        ~UpperTriMat() { delete[] A; }
};

void UpperTriMat::set(int r, int c, int el)
{
    if (r <= c && r > 0 && c > 0)
        A[r*(r-1)/2+c-1] = el; // row major formula: r*(r-1)/2 + c-1
}

int UpperTriMat::get(int r, int c)
{
    if (r <= c && r > 0 && c > 0)
        return A[r*(r-1)/2+c-1]; // row major formula: r*(r-1)/2 + c-1
    return 0;
}

void UpperTriMat::populate()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i <= j)
                set(i, j, 1);
}

void UpperTriMat::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
                cout << get(i, j) << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    int sz;
    cout << "Enter size of matrix: ";
    cin >> sz;
    UpperTriMat *mat = new UpperTriMat(sz);
    mat->populate();
    mat->display();
    mat->~UpperTriMat();
}