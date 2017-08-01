#ifndef STACK_H
#define STACK_H

#define SMAX 1024

struct stack {
    int data[SMAX];
    int top;
};

void init(struct stack *s);
void push(int *x, struct stack *s);
void pop(int *x, struct stack *s);
int empty(struct stack *s);
int top(struct stack *s);

#endif
