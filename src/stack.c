#include "stack.h"

void init(struct stack *s)
{
    s->top = -1;
}

void push(int *x, struct stack *s)
{
    s->top += 1;
    s->data[s->top] = *x;
}

void pop(int *x, struct stack *s)
{
    *x = s->data[s->top];
    s->top -= 1;
}

int empty(struct stack *s)
{
    return (s->top == -1);
}

int top(struct stack *s)
{
    return s->data[s->top];
}
