#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int row;
    int col;
    int item;
};

struct SparseMatrix
{
    int r;
    int c;
    int total_items;
    struct Element *elements;
};

/* This function creates a Sparse Matrix */
void create(struct SparseMatrix *s)
{
    printf("Enter Dimensions (# of rows, # of columns): ");
    scanf("%d%d", &s->r, &s->c);
    printf("Enter number of non-zero elements: ");
    scanf("%d", &s->total_items);
    s->elements = (struct Element *)malloc(sizeof(struct Element) * s->total_items);
    printf("Enter all non-zero elements in order from lo to hi: \n");
    for (int i = 0; i < s->total_items; i++)
        scanf("%d%d%d", &s->elements[i].row, &s->elements[i].col, &s->elements[i].item);
}

/* Add two sparse matrices */
struct SparseMatrix* add(struct SparseMatrix *s1, struct SparseMatrix *s2)
{
    // output matrix
    struct SparseMatrix *sum_matrix = (struct SparseMatrix*)malloc(sizeof(struct SparseMatrix)); 
    sum_matrix->r = s1->r; sum_matrix->c = s1->c;
    sum_matrix->elements = (struct Element*)malloc(sizeof(struct Element)*(s1->total_items + s2->total_items));
    int i = 0, j = 0, k = 0;
    while (i < s1->total_items && j < s2->total_items)
    {
        // Compare row numbers
        if (s1->elements[i].row < s2->elements[j].row)
            sum_matrix->elements[k++] = s1->elements[i++];
        else if (s1->elements[i].row > s2->elements[j].row)
            sum_matrix->elements[k++] = s2->elements[j++];
        else 
        {   // Compare column numbers
            if (s1->elements[i].col < s2->elements[j].col)
                sum_matrix->elements[k++] = s1->elements[i++];
            else if (s1->elements[i].col > s2->elements[j].col)
                sum_matrix->elements[k++] = s2->elements[j++];
            else // Row and Col are the same
            {
                sum_matrix->elements[k] = s1->elements[i];
                sum_matrix->elements[k++].item = s1->elements[i++].item + s2->elements[j++].item;
            }
        }
    }
    // Copy remaining elements from either
    for (; i < s1->total_items; i++) sum_matrix->elements[k++] = s1->elements[i];
    for (; j < s2->total_items; j++) sum_matrix->elements[k++] = s2->elements[j];
    sum_matrix->total_items = k; // set number of non-zero elements
    return sum_matrix;
}

void display(struct SparseMatrix *s)
{
    int k = 0;
    for (int i = 0; i < s->r; i++)
    {
        for (int j = 0; j < s->c; j++) 
        {
            if (i == s->elements[k].row && j == s->elements[k].col)
                printf("%d ", s->elements[k++].item);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct SparseMatrix *s1 = malloc(sizeof(struct SparseMatrix));
    struct SparseMatrix *s2 = malloc(sizeof(struct SparseMatrix));
    create(s1);
    create(s2);
    printf("First Matrix:\n");
    display(s1);
    printf("------------\n");
    printf("Second Matrix:\n");
    display(s2);
    printf("------------\n");
    struct SparseMatrix *sum_matrix = add(s1, s2);
    printf("Sum Matrix:\n");
    display(sum_matrix);
}