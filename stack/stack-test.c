#include "stack.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>

int main() {
    stack* S = stack_new();
    
    for (int i = 0; i < 100; i++) {
        push(S, (void*)(intptr_t) i);
        assert(stack_size(S) == i + 1);
        assert(stack_floor(S) == (void*)(intptr_t) 0);
        assert(top(S) == (void*)(intptr_t) i);
    }

    printf("%s\n", "Passed all tests!");
    return 0;
}