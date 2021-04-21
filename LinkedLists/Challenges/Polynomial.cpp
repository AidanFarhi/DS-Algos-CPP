#include <iostream>
#include <math.h>
using namespace std;

class PolyNode
{
    public:
    int coef;
    int exp;
    PolyNode *next;
    PolyNode(int co, int ex) { coef = co; exp = ex; next = NULL; }
};

class Poly
{
    public:
    int num_terms;
    PolyNode *first;
    Poly(){ first = NULL; } ;
    void initialize_poly();
    void display();
    void evaluate();
};

void Poly::initialize_poly()
{
    cout << "Enter number of terms: ";
    cin >> num_terms;
    cout << "Enter each term |<coef> <exp>| : " << endl;
    PolyNode *n;
    int co = 0, ex = 0;
    for (int i = 0; i < num_terms; i++)
    {
        cin >> co >> ex;
        if (first == NULL)
        {
            first = new PolyNode(co, ex);
            n = first;
        } else
        {
            n->next = new PolyNode(co, ex);
            n = n->next;
        }
    }
}

void Poly::display()
{
    PolyNode *n = first;
    for (int i = 0; i < num_terms; i++)
    {
        if (i == num_terms-1)
        {
            if (n->exp > 1)
                cout << n->coef << "x^" << n->exp << endl;
            else if (n->exp == 1)
                cout << n->coef << "x" << endl;
            else
                cout << n->coef << endl;
        }
        else
        {
            if (n->exp > 1)
                cout << n->coef << "x^" << n->exp << " + ";
            else if (n->exp == 1)
                cout << n->coef << "x + ";
            else
                cout << n->coef << " + ";
            n = n->next;
        }
    }
}

void Poly::evaluate()
{
    int x = 0;
    cout << "Enter an x value: ";
    cin >> x;
    double total = 0;
    PolyNode *n = first;
    for (int i = 0; i < num_terms; i++)
    {
        total += n->coef * (pow((double)x, (double)n->exp));
        n = n->next;
    }
    cout << "Result: " << total << endl;
}

int main()
{
    Poly *P = new Poly();
    P->initialize_poly();
    P->display();
    P->evaluate();
}