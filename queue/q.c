#include "q.h"

#include <stdlib.h>

struct node {
    elem val;
    struct node* next;
};

struct q {
    struct node* head;
    struct node* rear;
    int size;
};

q* q_new() {
    q* Q = malloc(sizeof(q));
    Q->head = NULL;
    Q->rear = NULL;
    Q->size = 0;

    return Q;
}

void enq(q* Q, elem x) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->val = x;
    new_node->next = NULL;

    if (Q->rear == NULL) {
        Q->head = Q->rear = new_node;
    }

    else {
        Q->rear->next = new_node;
        Q->rear = new_node;
    }

    Q->size++;
}

elem deq(q* Q) {
    if (q_empty(Q)) return NULL;

    struct node* temp = Q->head;
    elem ret = temp->val;

    Q->head = Q->head->next;

    if (Q->head == NULL) {
        Q->rear = NULL;
    }

    Q->size--;
    
    free(temp);

    return ret;
}

elem q_peek(q* Q) {
    if (q_empty(Q)) return NULL;

    return Q->head->val;
}

elem q_rear(q* Q) {
    if (q_empty(Q)) return NULL;

    return Q->rear->val;
}

bool q_empty(q* Q) {
    return Q->size == 0;
}

int q_size(q* Q) {
    return Q->size;
}

void q_free(q* Q) {
    while (!q_empty(Q)) {
        deq(Q);
    }

    free(Q);
}