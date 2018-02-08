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

/* 配列を用いた通常型線形探索、有無 */
int s1(int r[], int n, int k)
{
    int f = 0;
    int i;
    
    for (i = 0; (i < n-1) && (r[i] != k); i++) {
    }
    if (r[i] == k) {
        f = 1;
    }
    
    return f;
}

/* 配列を用いた通常型線形探索、場所 */
int s2(int r[], int n, int k)
{
    int f = -1;
    int i;
    
    for (i = 0; (i < n-1) && (r[i] != k); i++) {
    }
    if (r[i] == k) {
        f = i;
    }
    
    return f;
}

/* 配列を用いた通常型線形探索、レコード */
int s4(int r[], int n, int k)
{
    int f = -1;
    int i;
    
    for (i = 0; (i < n-1) && (r[i] != k); i++) {
    } 
    if (r[i] == k) {
        f = r[i];
    }
    
    return f;
}

/* 配列を用いた番兵型線形探索、有無 */
int t1(int r[], int n, int k)
{
    int f = 0;
    int i;
    
    r[n] = k;
    for (i = 0; r[i] != k; i++) {
    }
    if (r[i] == k && i != n) {
        f = 1;
    }
    
    return f;
}

/* 配列を用いた番兵型線形探索、場所 */
int t2(int r[], int n, int k)
{
    int f = -1;
    int i;
    
    r[n] = k;
    for (i = 0; r[i] != k; i++) {
    }
    if (r[i] == k && i != n) {
        f = i;
    }

    return f;
}

/* 配列を用いた番兵型線形探索、レコード */
int t4(int r[], int n, int k)
{
    int f = -1;
    int i;
    
    r[n] = k;
    for (i = 0; r[i] != k; i++) {
    }
    if (r[i] == k && i != n) {
        f = r[i];
    }
    
    return f;
}

/* 配列を用いたソート済み通常型線形探索、有無 */
int u1(int r[], int n, int k)
{
    int f = 0;
    int i;
    
    for (i = 0; (i < n-1) && (r[i] < k); i++) {
    }
    if (r[i] == k) {
        f = 1;
    }
    
    return f;
}

/* 配列を用いたソート済み通常型線形探索、場所 */
int u2(int r[], int n, int k)
{
    int f = -1;
    int i;
    
    for (i = 0; (i < n-1) && (r[i] < k); i++) {
    }
    if (r[i] == k) {
        f = i;
    }

    return f;
}

/* 配列を用いたソート済み通常型線形探索、レコード */
int u4(int r[], int n, int k)
{
    int f = -1;
    int i;
    
    for (i = 0; (i < n-1) && (r[i] < k); i++) {
    }
    if (r[i] == k) {
        f = r[i];
    }
    
    return f;
}

/* 配列を用いたソート済み番兵型線形探索、有無 */
int v1(int r[], int n, int k)
{
    int f = 0;
    int i;
    
    r[n] = k;
    for (i = 0; r[i] < k; i++) {
    }
    if (r[i] == k && i != n) {
        f = 1;
    }
    
    return f;
}

/* 配列を用いたソート済み番兵型線形探索、場所 */
int v2(int r[], int n, int k)
{
    int f = -1;
    int i;

    r[n] = k;
    for (i = 0; r[i] < k; i++) {
    }
    if (r[i] == k && i != n) {
        f = i;
    }

    return f;
}

/* 配列を用いたソート済み番兵型線形探索、レコード */
int v4(int r[], int n, int k)
{
    int f = -1;
    int i;
    
    r[n] = k;
    for (i = 0; r[i] < k; i++) {
    }
    if (r[i] == k && i != n) {
        f = r[i];
    }
    
    return f;
}

/* 配列を用いた重複ありの通常型線形探索、場所 */
int w2(int r[], int n, int k, int b[])
{
    int i;
    
    for (i = 0; i < n; i++) {
        if (r[i] == k) {
            b[i] = 1;
        }
    }
    
    return 0;
}

/* 配列を用いた重複ありの通常型線形探索、個数 */
int w3(int r[], int n, int k)
{
    int f = 0;
    int i;
    
    for (i = 0; i < n; i++) {
        if (r[i] == k) {
            f++;
 }
    }
    
    return f;
}

/* 配列を用いた重複ありの通常型線形探索、レコード */
int w4(int r[], int n, int k, int b[])
{
    int i;
    
    for (i = 0; i < n; i++) {
        if (r[i] == k) {
            b[i] = r[i];
        }
    } 
    
    return 0;
}

/* 配列を用いた重複ありの番兵型線形探索、場所 */
int x2(int r[], int n, int k, int b[])
{
    int i;
    
    r[n] = k;
    for (i = 0; i < n; i++) {
        if ((r[i] == k) && (i != n)) {
            b[i] = 1;
        }
    }
    
    return 0;
}

/* 配列を用いた重複ありの番兵型線形探索、個数 */
int x3(int r[], int n, int k)
{
    int f = 0;
    int i;
    
    r[n] = k;
    for (i = 0; i < n; i++) {
        if ((r[i] == k) && (i != n)) {
            f++;
        }
    }
    
    return f;
}

/* 配列を用いた重複ありの番兵型線形探索、レコード */
int x4(int r[], int n, int k, int b[])
{
    int i;
    
    r[n] = k;
    for (i = 0; i < n; i++) {
        if ((r[i] == k) && (i != n)) {
            b[i] = r[i];
        }
    }
    
    return 0;
}

/* 配列を用いた重複ありソートありの通常型線形探索、場所 */
int y2(int r[], int n, int k, int b[])
{
    int i;

    for (i = 0; (i < n) && (r[i] <= k); i++) {
        if (r[i] == k) {
            b[i] = 1;
        }
    } 
    
    return 0;
}

/* 配列を用いた重複ありソートありの通常型線形探索、個数 */
int y3(int r[], int n, int k)
{
    int f = 0;
    int i;
    
    for (i = 0; (i < n) && (r[i] <= k); i++) {
        if (r[i] == k) {
            f++;
        }
    } 
    
    return f;
}

/* 配列を用いた重複ありソートありの通常型線形探索、レコード */
int y4(int r[], int n, int k, int b[])
{
    int i;
    
    for (i = 0; (i < n) && (r[i] <= k); i++) {
        if (r[i] == k) {
            b[i] = r[i];
        }
    } 
    
    return 0;
}

/* 配列を用いた重複ありソートありの番兵型線形探索、場所 */
int z2(int r[], int n, int k, int b[])
{
    int i;
    
    r[n] = k;
    for (i = 0; (i < n) && (r[i] <= k); i++) {
        if ((r[i] == k) && (i != n)) {
            b[i] = 1;
        }
    } 
    
    return 0;
}

/* 配列を用いた重複ありソートありの番兵型線形探索、個数 */
int z3(int r[], int n, int k)
{
    int f = 0;
    int i;
    
    r[n] = k;
    for (i = 0; (i < n) && (r[i] <= k); i++) {
        if ((r[i] == k) && (i != n)) {
            f++;
        }
    }    
    
    return f;
}

/* 配列を用いた重複ありソートありの番兵型線形探索、レコード */
int z4(int r[], int n, int k, int b[])
{
    int i;
    
    r[n] = k;
    for (i = 0; (i < n) && (r[i] <= k); i++) {
        if ((r[i] == k) && (i != n)) {
            b[i] = r[i];
        }
    } 
    
    return 0;
}

int srch1(int r[], int n, int k)
{
    int f = 0;
    int i;
    
    for (i = 0; (i < n) && (f == 0); i++) {  
        if (r[i] == k) {
            f = 1;
        }
    }
    
    return f;
}

int srch2(int r[], int n, int k)
{
    int f = -1;
    int i;
    
    for (i = 0; (i < n) && (f == -1); i++) {
        if (r[i] == k) {
            f = i;
        }
    }
    
    return f;
}

int srch3(int head[], int next[], int k)
{
    int f = -1;
    int i = 0;
    
    while ((f == -1) && (i != -1)) {
        if (head[i] == k) {
            f = i;
        }
        i = next[i];
    }
    
    return f;
}
