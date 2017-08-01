#include <stdio.h>
#include "stack.h"
#include "search.h"

#define MAX 1024

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(void)
{
    int n, i, key;
    int k[MAX+1];
    struct stack stk;

    init(&stk);
    scanf("%d", &n);            /* レコード長 */
    scanf("%d", &key);          /* 探したいキー */
    for (i = 0; i < n; i++) {
        scanf("%d", &k[i]);
        /* push(&k[i],&stk); */
    }
    printf("%d ", n);
    printf("%d\n", key);
    print_array(k,n);

    if (search_array(k,n,key)) {
        printf("成功\n");
    } else {
        printf("失敗\n");
    }

    return 0;
}
