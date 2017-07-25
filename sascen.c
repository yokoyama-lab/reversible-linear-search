#include<stdio.h>
/*スタックを用いた昇順型*/
#define SMAX 1024

struct stack{
    int box[SMAX];
    int top;
};

void create(struct stack *s)
{
    s->top = -1;
}


void push(int *x,struct stack *s)
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

int aolinear(struct stack *s, int key, struct stack *t)
{
     int x;
     int f = -1;

     while(top(s) < key){
         pop(&x, s);
         push(&x, t);
     }
     if(top(s) == key){
         pop(&x, s);
         push(&x, t);
         if(!empty(s)){
             f = 1;
         }
     }

     return f;
}

int main(void)
{
     struct stack s;
     struct stack t;
     int key = 19;

     create(&s);
     create(&t);
     int x = 100;
     push(&x, &s);
     x = 19;
     push(&x, &s);
     x = 17;
     push(&x, &s);
     x = 15;
     push(&x, &s);
     x = 13;
     push(&x, &s);
     x = 11;
     push(&x, &s);
     x = 9;
     push(&x, &s);
     x = 7;
     push(&x, &s);
     x = 5;
     push(&x, &s);
     x = 3;
     push(&x, &s);
     x = 1;
     push(&x, &s);

     if(aolinear(&s,key,&t)==1){
        printf("成功\n");
           }
    else{
        printf("失敗\n");
    }

    return 0;

}

