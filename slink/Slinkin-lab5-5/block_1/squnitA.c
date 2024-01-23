#include "squnit.h"
#include <stdlib.h>
#include <stdio.h>

// Реализация функций для стека
pAStack AStack_create(int maxsize) {
    pAStack stack = malloc(sizeof(AStack));

    stack->data = malloc(maxsize * sizeof(int));
    stack->maxsize = maxsize;
    stack->count = 0;

    return stack;
}

void AStack_destroy(pAStack stack) {
    free(stack->data);
    free(stack);
}

void AStack_push(pAStack stack, int number) {
    if (!AStack_full(stack)) {
        stack->data[stack->count++] = number;
    }
    else 
        printf("[Стек полон]\n");
}

int AStack_pop(pAStack stack) {
    if (!AStack_empty(stack)) {
        return stack->data[--stack->count];
    }

    return 1; 
}

int AStack_empty(pAStack stack) {
    return stack->count == 0;
}

int AStack_full(pAStack stack) {
    return stack->count == stack->maxsize;
}

int AStack_count(pAStack stack) {
    return stack->count;
}


paQueue aQueue_create(int maxsize) {
    paQueue que = malloc(sizeof(aQueue));

    que->data = malloc(maxsize * sizeof(int));
    que->maxsize = maxsize;
    que->first = 0;
    que->last = -1; 

    return que;
}

void aQueue_destroy(paQueue que) {
    free(que->data);
    free(que);
}

void aQueue_put(paQueue que, int number) {
    if (!aQueue_full(que)) {
        que->last++;
        que->data[que->last % que->maxsize] = number;
    }
}

int aQueue_get(paQueue que) {
    if (!aQueue_empty(que)) {
        que->first++;
        return que->data[(que->first - 1) % que->maxsize];
    }
    return 1; 
}

int aQueue_empty(paQueue que) {
    return que->last - que->first + 1 == 0;
}

int aQueue_full(paQueue que) {
    return que->last - que->first + 1 == que->maxsize;
}

int aQueue_count(paQueue que) {
    return que->last - que->first + 1;
}
