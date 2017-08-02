#ifndef SEARCH_H
#define SEARCH_H

int search_array(int k[], int n, int key);
int search_stack(struct stack *s, int key);
int search_array_sentinel(int k[], int n, int key);
int search_stack_sentinel(struct stack *s, int key);
int search_sorted_array_sentinel(int k[], int n, int key);
int search_sorted_stack_sentinel(struct stack *s, int key);

#endif
