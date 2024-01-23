#include <stdio.h>
#include "squnitL.h"

int main() {
    pLStack stack;
    pLQueue queue;
    int num;

    stack = LStack_create(10);
    LStack_push(&stack, 22);
    LStack_push(&stack, 33);
    LStack_push(&stack, 44);
    printf("Pop: %d\n", LStack_pop(&stack));
    printf("Empty: %d\n", LStack_empty(stack));
    printf("Full: %d\n", LStack_full(stack));
    printf("Count: %d\n", LStack_count(stack));
    LStack_destroy(stack);

    printf("=====\n");

    queue = LQueue_create(10);
    LQueue_put(queue, 22);
    LQueue_put(queue, 33);
    printf("Получен: %d\n", LQueue_get(&queue));
    LQueue_put(queue, 33);
    printf("Получен: %d\n", LQueue_get(&queue));
    printf("Empty: %d\n", LQueue_empty(queue));
    printf("Full: %d\n", LQueue_full(queue));
    printf("Count: %d\n", LQueue_count(queue));
    LQueue_destroy(queue);

    return 0;
}
