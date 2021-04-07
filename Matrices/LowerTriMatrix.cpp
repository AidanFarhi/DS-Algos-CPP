#include <iostream>
using namespace std;

/* Row major mapping formula: (r*r+1/2) + c+1 */

class LowerTriMatrix
{
private:
    int *A;
    int n;
public:
    LowerTriMatrix(int size)
    {
        n = size;
        A = new int[n*n/2];
    }
    void set(int r, int c, int el);
    int get(int r, int c);
    void display();
    ~LowerTriMatrix() { delete []A; }
};

void LowerTriMatrix::set(int r, int c, int el)
{
    if (r >= c && r >= 0 && c >= 0 && el > 0)
        A[r*r+1/2+c+1] = el;
}

int LowerTriMatrix::get(int r, int c)
{
    if (r >= c && r >= 0 && c >= 0)
        return A[r*r+1/2+c+1];
    return 0;
}

void LowerTriMatrix::display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
                cout << A[i*i+1/2+j+1] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    LowerTriMatrix *m = new LowerTriMatrix(5);
    int num = 1;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (i >= j)
                m->set(i, j, num);
    m->display();
    m->set(4, 4, 5);
    m->display();
    m->~LowerTriMatrix();
}