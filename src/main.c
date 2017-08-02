#include <stdio.h>
#include <stdlib.h>             /* malloc */
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

void print_result(int v)
{
    printf(v ? "成功\n" : "失敗\n");
}

int main(void)
{
    int n, i, key, sorted;
    int k[MAX+1];
    struct stack *stk     = (struct stack *)malloc(sizeof(struct stack));
    struct stack *stk_tmp = (struct stack *)malloc(sizeof(struct stack));

    init(stk);
    scanf("%d", &sorted);
    scanf("%d", &n);            /* レコード長 */
    scanf("%d", &key);          /* 探したいキー */
    for (i = 0; i < n; i++) {
        scanf("%d", &k[i]);
    }
    for (i = n-1; i >= 0; i--) {
        push(&k[i],stk);
    }
    printf("sorted=%d, n=%d, key=%d\n", sorted, n, key);
    print_array(k,n);

    print_result(search_array(k,n,key));
    print_result(search_array_sentinel(k,n,key));
    copy(stk,stk_tmp);
    print_result(search_stack(stk_tmp,key));
    copy(stk,stk_tmp); add_sentinel(key,stk_tmp);
    print_result(search_stack_sentinel(stk_tmp,key));
    if (sorted) {
        print_result(search_sorted_array_sentinel(k,n,key));
        copy(stk,stk_tmp);
        print_result(search_sorted_stack_sentinel(stk_tmp,key));
    }

    return 0;
}
