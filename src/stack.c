#include "stack.h"

void init(struct stack *s)
{
    s->top = -1;
}

void push(int *x, struct stack *s)
{
    s->top += 1;
    s->box[s->top] = *x;
}

void pop(int *x, struct stack *s)
{
    *x = s->box[s->top];
    s->top -= 1;
}

int empty(struct stack *s)
{
    return (s->top == -1);
}

int top(struct stack *s)
{
    return s->box[s->top];
}
