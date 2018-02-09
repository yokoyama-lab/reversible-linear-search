#include <stdio.h>
#include <stdlib.h>             /* malloc */
#include "stack.h"
#include "search.h"

#define MAX 1024

void print_array(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void print_result(int v)
{
    printf(v ? "成功\n" : "失敗\n");
}

void print(int p)
{
    printf("%d\n",p);
}

void print_a(int a[], int n)
{
    int i;

    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    printf("\n");
}

int main(void)
{
    int n, i, key, sorted,some;
    int k[MAX+1];
    int b[MAX+1];
    struct stack *stk     = (struct stack *)malloc(sizeof(struct stack));
    struct stack *stk_tmp = (struct stack *)malloc(sizeof(struct stack));

    init(stk);
    printf("ソート(有:1 無:0)");
    scanf("%d", &sorted);
    printf("重複(有:1 無:0)");
    scanf("%d", &some);
    printf("レコード長(max 1024) = "); scanf("%d", &n);            /* レコード長 */
    printf("キー値 = "); scanf("%d", &key);          /* 探したいキー */
    for (i = 0; i < n; i++) {
        printf("%d番目の配列の中身 = ", i);
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
    if (sorted==0) {
        if (some==0) {
            print(s1(k,n,key));
            print(s2(k,n,key));
            print(s4(k,n,key));
            print(t1(k,n,key));
            print(t2(k,n,key));
            print(t4(k,n,key));
        } else {
            w2(k,n,key,b);
            print_a(b,n);
            print(w3(k,n,key));
            w4(k,n,key,b);
            print_a(b,n);
            x2(k,n,key,b);
            print_a(b,n);
            print(x3(k,n,key));
            x4(k,n,key,b);
            print_a(b,n);
        }
    } else {
        print_result(search_sorted_array_sentinel(k,n,key));
        copy(stk,stk_tmp);
        print_result(search_sorted_stack_sentinel(stk_tmp,key));
        if (some==0) {
            print(u1(k,n,key));
            print(u2(k,n,key));
            print(u4(k,n,key));
            print(v1(k,n,key));
            print(v2(k,n,key));
            print(v4(k,n,key));
        } else {
            y2(k,n,key,b);
            print_a(b,n);
            print(y3(k,n,key));
            y4(k,n,key,b);
            print_a(b,n);
            z2(k,n,key,b);
            print_a(b,n);
            print(z3(k,n,key));
            z4(k,n,key,b);
            print_a(b,n);
        }
    }

    return 0;
}
