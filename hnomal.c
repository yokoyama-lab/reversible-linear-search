#include<stdio.h>
/*配列を用いた通常型*/
int linear(int k[], int key, int n, int f)
{
    int i;

    for (i = 0; (i < n) && (f == -1); i++){
              if (k[i] == key){
                       f = 1;
              }
    }

    return f;
}

int main(void)
{
    int k[5] = {33, 21, 64, 75, 19};
    int key = 31;
    int n = 5;
    int f = -1;

    if (linear(k, key, n, f) == 1){
            printf("成功\n");
    }
    else{
            printf("失敗\n");
    }

    return 0;
}
