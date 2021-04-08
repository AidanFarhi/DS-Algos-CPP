#include <stdio.h>

struct DiagMatrix
{
    int A[10];
    int n;
};

void Set(struct DiagMatrix *m, int r, int c, int el)
{
    if (r == c && el > 0) m->A[r] = el;
}

int Get(struct DiagMatrix m, int r, int c)
{
    if (r == c) 
        return m.A[r];
    else
        return 0;
}

void Display(struct DiagMatrix m)
{
    for (int i = 0; i < m.n; i++)
    {
        for (int j = 0; j < m.n; j++)
        {
            if (i == j)
                printf("%d ", m.A[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct DiagMatrix m;
    m.n = 4; // 4 x 4 matrix
    Set(&m, 0, 0, 1); Set(&m, 1, 1, 2); Set(&m, 2, 2, 3); Set(&m, 3, 3, 4);
    Display(m);
}