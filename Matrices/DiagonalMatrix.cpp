#include <iostream>

class DiagonalMatrix
{
private:
    int n;  // size of matrix -> n x n
    int *A; // pysical array of diagonal elements in matrix

public:
    /* Constructor */
    DiagonalMatrix(int size)
    {
        n = size;
        A = new int[n];
    }
    /* Method Definitions */
    void set(int r, int c, int el);
    int get(int r, int c);
    void display();
    /* Destructor */
    ~DiagonalMatrix() { delete []A; }
};

/* Method Implementations using Scope Resolution */
void DiagonalMatrix::set(int r, int c, int el) 
{
    if (r == c && r >= 0 && c >= 0 && el > 0)
        A[r] = el;
}

int DiagonalMatrix::get(int r, int c)
{
    if (r == c && r >= 0 && c >= 0)
        return A[r];
    return 0;
}

void DiagonalMatrix::display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                std::cout << A[i] << " ";
            else
                std::cout << "0 ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    DiagonalMatrix *m = new DiagonalMatrix(4);
    m->set(0, 0, 1); m->set(1, 1, 2); m->set(2, 2, 3); m->set(3, 3, 4);
    m->display();
    m->~DiagonalMatrix();
}
