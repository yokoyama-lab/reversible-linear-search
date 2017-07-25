#include<stdio.h>
/*配列を用いた番兵法*/
int banpei(int k[], int key, int n)
{
     int i = 0;
     int f;

     k[n] = key;

     while (k[i] != key) {
          i++;
     }

     if (i < n){
         f = 1;
     }
     else{
         f = -1;
     }

     return f;
}

int main(void)
{
     int k[6]= {33, 21, 64, 75, 19};
     int key = 191;
     int n = 5;

     if (banpei(k, key, n) == 1){
         printf("成功\n");
     }
     else{
         printf("失敗\n");
     }

     return 0;

}
