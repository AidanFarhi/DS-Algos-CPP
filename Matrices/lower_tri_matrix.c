#include <stdio.h>
#include <stdlib.h>

struct LowerTriMatrix
{
    int *A;
    int n;
};

/* Sets an element at given row and column. (Indexes start at 1). */
void set(struct LowerTriMatrix *m, int r, int c, int el)
{
    if (r >= c && r > 0 && c > 0 && el > 0)
        m->A[r*(r-1)/2+c-1] = el; // Row major formula: r(r-1) / 2 + c-1
}

int get(struct LowerTriMatrix m, int r, int c)
{
    if (r >= c && r > 0 && c > 0)
        return m.A[r*(r-1)/2+c-1]; // Row major formula: r(r-1) / 2 + c-1
    return 0; // element not in matrix or is zero
}

void display(struct LowerTriMatrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if (i >= j)
                printf("%d ", m.A[i*(i-1)/2+j-1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct LowerTriMatrix ltm;
    printf("Enter Dimensions of Matrix: ");
    scanf("%d", &ltm.n);
    ltm.A = (int*) malloc(sizeof(int) * (ltm.n*(ltm.n+1)/2));
    // Fill lower triangle
    for (int i = 1; i <= ltm.n; i++)
        for (int j = 1; j <= ltm.n; j++)
            if (i >= j)
                set(&ltm, i, j, 1);
    display(ltm);
    free(ltm.A);
}