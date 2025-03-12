#ifndef Q_H
#define Q_H

#include <stdbool.h>

typedef void* elem;

typedef struct node node;
typedef struct q q;

q* q_new();
void q_free(q* Q);

void enq(q* q, elem x);
elem deq(q* q);
elem q_peek(q* q);
elem q_rear(q* q);
bool q_empty(q* q);
int q_size(q* q);

#endif