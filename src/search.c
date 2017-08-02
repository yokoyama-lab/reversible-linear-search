#include "stack.h"

/* 配列を用いた通常型線形探索 */
int search_array(int k[], int n, int key)
{
    int f = 0;
    int i;

    for (i = 0; (i < n) && (f == 0); i++) {
        if (k[i] == key) {
            f = 1;
        }
    }

    return f;
}

/* スタックを用いた通常型線形探索 */
int search_stack(struct stack *s, int key)
{
    int f = 0;
    int x;

    while (!empty(s) && f == 0) {
        if (top(s) == key) {
            f = 1;
        }
        pop(&x, s);
    }

    return f;
}

/* 配列と番兵を用いた線形探索 */
/* 配列 k の長さは少なくとも n 以上であると仮定する */
int search_array_sentinel(int k[], int n, int key)
{
    int i = 0;

    k[n] = key;
    while (k[i] != key) {
        i++;
    }

    return i < n;
}

/* スタックと番兵を用いた線形探索 */
/* スタック s の一番下の要素が番兵であると仮定する */
int search_stack_sentinel(struct stack *s, int key)
{
    int x;

    while (top(s) != key) {
        pop(&x, s);
    }
    pop(&x, s);

    return !empty(s);
}

/* 配列と番兵を用いた昇順型線形探索 */
/* 配列 k の要素は昇順に整列されていると仮定する */
/* 配列 k の長さは少なくとも n 以上であると仮定する */
int search_sorted_array_sentinel(int k[], int n, int key)
{
    int i = 0;
    k[n] = key;
    while (key > k[i]) {
        i++;
    }

    return i != n;
}

/* スタックを用いた昇順型線形探索 */
/* スタック s の要素は昇順に整列されていると仮定する */
/* スタック s の一番下の要素は番兵と仮定する */
int search_sorted_stack_sentinel(struct stack *s, int key)
{
    int x;
    while (key > top(s)) {
        pop(&x, s);
    }
    pop(&x, s);

    return !empty(s);
}
