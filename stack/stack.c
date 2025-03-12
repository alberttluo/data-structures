#include "stack.h"

#include <stdlib.h>

struct node {
    elem val;
    struct node* next;
};

struct stack {
    struct node* head;
    struct node* floor;
    int size;
};

struct stack* stack_new() {
    stack* S = malloc(sizeof(stack));
    S->head = NULL;
    S->floor = NULL;
    S->size = 0;

    return S;
}

void push(stack* S, elem x) {
    node* new_node = malloc(sizeof(node));
    new_node->val = x;
    new_node->next = S->head;

    if (S->head == NULL) {
        S->floor = new_node;
    }

    S->head = new_node;
    S->size++;
}

elem pop(stack* S) {
    if (stack_empty(S)) return NULL;

    node* temp = S->head;
    elem ret = temp->val;

    S->head = S->head->next;

    if (S->floor == temp) {
        S->floor = NULL;
    }

    free(temp);
    return ret;
}

elem top(stack* S) {
    if (stack_empty(S)) return NULL;

    return S->head->val;
}

elem stack_floor(stack* S) {
    if (stack_empty(S)) return NULL;

    return S->floor->val;
}

bool stack_empty(stack* S) {
    return S->size == 0;
}

int stack_size(stack* S) {
    return S->size;
}

void stack_free(stack* S) {
    while (!stack_empty(S)) {
        elem x = pop(S);
    }

    free(S);
}