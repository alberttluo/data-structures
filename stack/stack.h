#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef void* elem;
typedef struct node node;
typedef struct stack stack;

stack* stack_new();
void stack_free(stack* S);

void push(stack* S, elem x);
elem pop(stack* S);
elem top(stack* S);
elem stack_floor(stack* S);
bool stack_empty(stack* S);
int stack_size(stack* S);

#endif