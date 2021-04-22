#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Write a program that converts an Infix expression to Postfix.
 * ex) [4 + 5 * 2] -> [5 2 * 4 +]
 * 
 *        Prec. | As.
 * __________________
 * | +, - | 1 | L-R |
 * ------------------
 * | *, / | 2 | L-R |
 * ------------------
 * | oper.| 3 | N/A |
 * ------------------
 */

typedef struct Stack
{
    int top;
    char *st;
} Stack;

Stack* stack_constructor(int sz)
{
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->st = (char*) malloc(sizeof(char) * sz);
    stack->top = -1;
    return stack;
}

void push(Stack *s, char ch)
{
    s->st[++s->top] = ch;
}

char pop(Stack *s)
{
    return s->st[s->top--];
}

int is_empty(Stack *s)
{
    return s->top == -1 ? 1 : 0;
}

char top(Stack *s)
{
    return s->st[s->top];
}

int is_operand(char ch)
{
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*') return 0;
    return 1;
}

int prec(char ch)
{
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}

char* convert(char *infix)
{
    Stack *stack = stack_constructor(strlen(infix)+1);
    char *postfix = (char *) malloc(sizeof(char) * strlen(infix)+1);
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (is_operand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (prec(infix[i]) > prec(top(stack)))
                push(stack, infix[i++]);
            else
                postfix[j++] = pop(stack);
        }
    }
    while (!is_empty(stack))
        postfix[j++] = pop(stack);
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *input;
    while (1)
    {
        printf("Enter and expression: ");
        scanf("%s", input);
        char *result = convert(input);
        printf("%s\n", result);
    }
}