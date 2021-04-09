#include <iostream>
using namespace std;

class Element
{
    public:
    int row;
    int col;
    int val;
};

class SparseMatrix
{
private:
    int rows;
    int columns;
    int num_elements;
    Element *elements;
public:
    SparseMatrix(int r, int c, int num)
    {
        rows = r;
        columns = c;
        num_elements = num;
        elements = new Element[num_elements];
    }
    SparseMatrix* add(SparseMatrix *sm2);
    void read();
    void display();
    ~SparseMatrix() { delete[] elements; }
};

SparseMatrix* SparseMatrix::add(SparseMatrix *sm2)
{
    // output matrix
    SparseMatrix *sum_matrix = new SparseMatrix(sm2->rows, sm2->columns, (num_elements+sm2->num_elements)); 
    int i = 0, j = 0, k = 0;
    while (i < num_elements && j < sm2->num_elements)
    {
        // Compare row numbers
        if (elements[i].row < sm2->elements[j].row)
            sum_matrix->elements[k++] = elements[i++];
        else if (elements[i].row > sm2->elements[j].row)
            sum_matrix->elements[k++] = sm2->elements[j++];
        else 
        {   // Compare column numbers
            if (elements[i].col < sm2->elements[j].col)
                sum_matrix->elements[k++] = elements[i++];
            else if (elements[i].col > sm2->elements[j].col)
                sum_matrix->elements[k++] = sm2->elements[j++];
            else // Row and Col are the same
            {
                sum_matrix->elements[k] = elements[i];
                sum_matrix->elements[k++].val = elements[i++].val + sm2->elements[j++].val;
            }
        }
    }
    // Copy remaining elements from either
    for (; i < num_elements; i++) sum_matrix->elements[k++] = elements[i];
    for (; j < sm2->num_elements; j++) sum_matrix->elements[k++] = sm2->elements[j];
    return sum_matrix;
}

void SparseMatrix::read()
{
    cout<<"Enter all non-zero elements:\n";
    for (int i = 0; i < num_elements; i++)
        cin>>elements[i].row>>elements[i].col>>elements[i].val;
}

void SparseMatrix::display()
{
    int k = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i == elements[k].row && j == elements[k].col)
                cout << elements[k++].val << " ";
            else
                cout << "0 ";
        }
        cout<<endl;
    }
}

int main()
{
    SparseMatrix *sm1 = new SparseMatrix(5, 5, 5);
    SparseMatrix *sm2 = new SparseMatrix(5, 5, 5);
    sm1->read();
    sm2->read();
    cout<<"First Matrix:\n";
    sm1->display();
    cout<<"Second Matrix:\n";
    sm2->display();
    SparseMatrix *sm3 = sm1->add(sm2);
    cout<<"Sum Matrix:\n";
    sm3->display();
}
