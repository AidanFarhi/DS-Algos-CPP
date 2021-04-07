#include <stdio.h>
#include <stdlib.h>

struct LowerTriMatrix
{
    int *A;
    int n;
};

/* Row major mapping formula: (r*r+1/2) + c+1 */
void set(struct LowerTriMatrix *m, int r, int c, int el)
{
    if (r >= c && r >= 0 && c >= 0 && el > 0)
        m->A[(r*r+1)/2+c+1] = el;
}

int get(struct LowerTriMatrix m, int r, int c)
{
    if (r >= c && r >= 0 && c >= 0)
        return m.A[(r*r+1)/2+c+1];
    return 0;
}

void display(struct LowerTriMatrix m)
{
    for (int i = 0; i < m.n; i++)
    {
        for (int j = 0; j < m.n; j++)
        {
            if (i >= j)
                printf("%d ", m.A[i*i+1/2+j+1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct LowerTriMatrix m;
    m.n = 5;
    m.A = (int *) malloc(((m.n*m.n)/2) * sizeof(int));
    int num = 1;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (i >= j)
                m.A[i*i+1/2+j+1] = num;
    display(m);
    free(m.A);
}