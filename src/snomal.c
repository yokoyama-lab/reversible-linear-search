/* スタックを用いた通常型 */

#include <stdio.h>
#include "stack.h"

int linear(struct stack *s, int key)
{
    int f = -1;
    int x;

    while (!empty(s) && f == -1) {
        if (top(s) == key) {
            f = 1;
        }
        pop(&x, s);
    }

    return f;
}

int main(void)
{
    struct stack s;
    int key = 11;
    int x;

    create(&s);
    x= 1;
    push(&x, &s);
    x = 2;
    push(&x, &s);
    x = 3;
    push(&x, &s);
    x = 4;
    push(&x, &s);
    x = 5;
    push(&x, &s);
    x = 6;
    push(&x, &s);
    x = 7;
    push(&x, &s);
    x = 8;
    push(&x, &s);
    x = 9;
    push(&x, &s);
    x = 10;
    push(&x, &s);

    printf(linear(&s, key) == 1 ? "成功\n" : "失敗\n");

    return 0;
}
