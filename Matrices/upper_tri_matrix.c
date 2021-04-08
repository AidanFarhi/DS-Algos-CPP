#include <stdio.h>
#include <stdlib.h>

typedef struct UpperTriMat
{
    int *A;
    int n;
} UpperTriMat;

void set(UpperTriMat *mat, int r, int c, int el)
{
    if (r <= c && r > 0 && c > 0)
        mat->A[r*(r-1)/2+c-1] = el;
}

int get(UpperTriMat *mat, int r, int c)
{
    if (r <= c && r > 0 && c > 0)
        return mat->A[r*(r-1)/2+c-1];
    return 0;
}

void populate(UpperTriMat *mat)
{
    for (int i = 1; i <= mat->n; i++)
        for (int j = 1; j <= mat->n; j++)
            if (i <= j)
                set(mat, i, j, 1);
}

void display(UpperTriMat *mat)
{
    for (int i = 1; i <= mat->n; i++)
    {
        for (int j = 1; j <= mat->n; j++)
        {
            if (i <= j)
                printf("%d ", get(mat, i, j));
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    UpperTriMat *mat = malloc(sizeof(UpperTriMat));
    printf("Enter matrix size: ");
    scanf("%d", &mat->n);
    mat->A = (int *) malloc(sizeof(int) * (mat->n*(mat->n+1)/2));
    populate(mat);
    display(mat);
    free(mat->A);
    free(mat);
}