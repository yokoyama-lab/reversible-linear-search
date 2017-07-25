
#include<stdio.h>
/*スタックを用いた通常型*/
#define SMAX 1024

struct stack{
     int box[SMAX];
     int top;
};

void create(struct stack *s)
{
     s->top = -1;
}


void push(int *x, struct stack *s)
{
     s->top += 1;
     s->box[s->top] = *x;
     *x = 0;
}

void pop(int *x, struct stack *s)
{
     *x = s->box[s->top];
     s->top -= 1;
}

int empty(struct stack *s)
{
     return (s->top == -1);
}

int top(struct stack *s)
{
     return s->box[s->top];
}

int linear(struct stack *s, int key, struct stack *t)
{
     int f = -1;
     int x;

     while(!empty(s) && f == -1){
         if(top(s) == key){
             f=1;
         }
         pop(&x, s);
         push(&x, t);
     }
     return f;
}



int main(void)
{
     struct stack s;
     struct stack t;
     int key = 11;

     create(&s);
     create(&t);
     int x = 1;
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

     if(linear(&s, key, &t) == 1){
         printf("成功\n");
     }
     else{
         printf("失敗\n");
     }

     return 0;

}


