#include<stdio.h>
/*配列を用いた昇順型*/
int aolinear(int k[], int key, int n, int f)
{
     int i = 0;

     while (key > k[i]){
           i++;
     }

     if (k[i] == key && i != n){
         f = 1;
     }
     else{
         f = -1;
     }

     return f;
}


int main(void)
{
     int k[6] = {19, 21, 37, 64, 75, 32767};
     int n=5;
     int key = 32767;
     int f = 0;

     if (aolinear(k, key, n, f) == 1){
         printf("成功\n");
     }
     else{
         printf("失敗\n");
     }

     return 0;
}
