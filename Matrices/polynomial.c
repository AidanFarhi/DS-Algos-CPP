#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Term
{
    int coef;
    int exp;
} Term;

typedef struct Poly
{
    int num_terms;
    Term *terms;
} Poly;

/* Takes in an x value that will be plugged into polynomial and computed. */
int evaluate(Poly *p)
{
    int x;
    printf("Enter in x: ");
    scanf("%d", &x);
    int sum = 0;
    for (int i = 0; i < p->num_terms; i++)
    {
        sum += p->terms[i].coef * (int)pow(x, p->terms[i].exp);
    }
    return sum;
}

/* Combines like terms for two polynomials. Terms exponents must be in standard decreasing order. */
Poly* combine(Poly *p1, Poly *p2)
{
    Poly *result = malloc(sizeof(Poly));
    result->terms = malloc(sizeof(Term)*(p1->num_terms * p2->num_terms));
    int i = 0, j = 0, k = 0;
    while (i < p1->num_terms && j < p2->num_terms)
    {
        if (p1->terms[i].exp > p2->terms[j].exp)
        {
            result->terms[k++] = p1->terms[i++];
        } else if (p1->terms[i].exp < p2->terms[j].exp)
        {
            result->terms[k++] = p2->terms[j++];
        } else
        {
            result->terms[k].coef = p1->terms[i].coef + p2->terms[j++].coef;
            result->terms[k++].exp = p1->terms[i++].exp;
        }
    }
    for (; i < p1->num_terms; i++) result->terms[k++] = p1->terms[i];
    for (; j < p2->num_terms; j++) result->terms[k++] = p2->terms[j];
    result->num_terms = k;
    return result;
}

void display(Poly *p)
{
    for (int i = 0; i < p->num_terms; i++)
    {
        if (i == p->num_terms - 1)
        {
            printf("%dx^%d\n", p->terms[i].coef, p->terms[i].exp); 
            break;
        }
        printf("%dx^%d + ", p->terms[i].coef, p->terms[i].exp);
    }
}

void initialize(Poly *poly)
{
    printf("Enter number of terms: ");
    scanf("%d", &poly->num_terms);
    poly->terms = malloc(sizeof(Term) * poly->num_terms);
    for (int i = 0; i < poly->num_terms; i++)
    {
        printf("Entering term number %d format-> <coef> <exp>: ", i+1);
        scanf("%d%d", &poly->terms[i].coef, &poly->terms[i].exp);
    }
}

int main()
{
    Poly *poly = malloc(sizeof(Poly));
    Poly *poly2 = malloc(sizeof(Poly));
    Poly *poly3 = malloc(sizeof(Poly));
    initialize(poly);
    initialize(poly2);
    display(poly);
    display(poly2);
    poly3 = combine(poly, poly2);
    display(poly3);
}