#include <stdio.h>
#include "squnit.h"

int main() {
    pAStack stack = NULL;
    paQueue queue = NULL;
    int num;

    stack = AStack_create(1);
    //AStack_push(stack, 11);
    //AStack_push(stack, 12);
    //AStack_push(stack, 13);
    AStack_push(stack, 14);

    //printf("Удален: %d\n", AStack_pop(stack));
    AStack_push(stack, 14);
    printf("Empty: %d\n", AStack_empty(stack));
    printf("Full: %d\n", AStack_full(stack));
    printf("Count: %d\n", AStack_count(stack));

    for (int i = 0; i < stack->count; i++) {
        printf("Data: %d\n", stack->data[i]);
    }

    AStack_destroy(stack);

    printf("=======\n");
    queue = aQueue_create(300);

    //aQueue_put(queue, 12);
    //aQueue_put(queue, 15);

    //printf("Удален: %d\n", aQueue_get(queue));
    //aQueue_put(queue, 14);
    //printf("Удален: %d\n", aQueue_get(queue));
    //printf("Удален: %d\n", aQueue_get(queue));

    for (int i = 0;i < 200;i++) {
        aQueue_put(queue, 15);
    }

    for (int i = 0;i < 200;i++) {
        aQueue_get(queue);
    }

    for (int i = 0;i < 10;i++) {
        aQueue_put(queue, i);
    }

    for (int i = 0;i < 10;i++) {
        printf("Удален: %d\n", aQueue_get(queue));
    }

    

    printf("Empty: %d\n", aQueue_empty(queue));
    printf("Full: %d\n", aQueue_full(queue));
    printf("Count: %d\n", aQueue_count(queue));

    for (int i = 0; i < aQueue_count(queue); i++) {
        printf("Data: %d\n", queue->data[i]);
    }

    aQueue_destroy(queue);
}