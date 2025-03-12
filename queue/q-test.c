#include "q.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>

int main() {
    q* Q = q_new();

    for (int i = 0; i < 100; i++) {
        enq(Q, (void*)(intptr_t) i);
        assert(q_size(Q) == i + 1);
        assert(q_peek(Q) == (void*)(intptr_t) 0);
        assert(q_rear(Q) == (void*)(intptr_t) i);
    }

    assert(q_size(Q) == 100);

    for (int i = 0; i < 50; i++) {
        deq(Q);
        assert(q_size(Q) == 100 - (i + 1));
        assert(q_peek(Q) == (void*)(intptr_t)(i + 1));
        assert(q_rear(Q) == (void*)(intptr_t)(99));
    }

    assert(q_size(Q) == 50);

    printf("%s\n", "Passed all tests!");

    return 0;
}