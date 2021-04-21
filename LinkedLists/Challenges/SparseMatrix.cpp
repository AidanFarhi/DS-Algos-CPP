#include <iostream>
using namespace std;

/**
 * Create a sparse matrix representation using an array of linked lists.
 * 
 * Methods:
 * Create()
 * Display()
 * Add()
 */

class Node
{
    public:
    int col;
    int data;
    Node *next;
    Node(int c, int d) { col = c; data = d; next = NULL; }
};

class LL
{
    public:
    Node *head;
    LL() { head = NULL; }
    void insert_node(Node *n);
};

void LL::insert_node(Node *n)
{
    if (head == NULL) head = n;
    else
    {
        Node *i = head;
        Node *prev = NULL;
        while (i)
        {
            if (i->col > n->col)
            {
                prev->next = n;
                n->next = i;
                break;
            }
            prev = i;
            i = i->next;
        }
        // new node is at the end of the list
        if (i == NULL) prev->next = n; 
    }
}

class SparseMatrix
{
    public:
    LL **rows; // an array of linked list pointers
    int R;    // Number of rows
    int C;    // Number of columns
    /* Constructor where only dimensions are given */
    SparseMatrix(int r, int c)
    {
        R = r;
        C = c;
        rows = new LL*[R];
        for (int i = 0; i < R; i++)
            rows[i] = new LL();
    }
    void insert_value(int row, int col, int val);
    void display();
};

void SparseMatrix::insert_value(int row, int col, int val)
{
    if (row < R && col < C && row >= 0 && col >= 0)
    {
        Node *n = new Node(col, val);
        rows[row]->insert_node(n);
    }
}

void SparseMatrix::display()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            bool flag = false;
            if (rows[i]->head != NULL)
            {
                Node *n = rows[i]->head;
                while (n)
                {
                    if (n->col == j)
                    { 
                        flag = true;
                        cout << n->data << " ";
                        break;
                    }
                    n = n->next;
                }
            }
            if (!flag) cout << "0 ";
        }   
        cout << endl;
    }
}

int main()
{
    int R = 0, C = 0;
    int num_items = 0;
    cout << "Enter the dimensions <row count> <col count>: ";
    cin >> R >> C;
    cout << "Enter number of non-zero elements <int>: ";
    cin >> num_items;
    // Now make the Sparse Matrix
    SparseMatrix *SM = new SparseMatrix(R, C);
    cout << "Enter each item <row> <col> <val>" << endl;
    int row = 0, col = 0, val = 0;
    for (int i = 0; i < num_items; i++)
    {
        cin >> row >> col >> val;
        SM->insert_value(row, col, val);
    }
    SM->display();
}