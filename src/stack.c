#include <stdio.h>              /* for printf */
#include "stack.h"

void init(struct stack *s)
{
    s->top = -1;
}

void push(int *x, struct stack *s)
{
    s->top++;
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

/* s (source) から t (target) へコピーする */
void copy(struct stack *s, struct stack *t)
{
    *t = *s;
}

void print_stack(struct stack *s)
{
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

/* 補助関数 */
void add_sentinel(int v, struct stack *s)
{
    int i;
    s->top++;
    for (i = s->top; i > 0; i--) {
        s->data[i] = s->data[i - 1];
    }
    s->data[0] = v;
}
