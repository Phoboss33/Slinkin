#include "squnitL.h"
#include <stdlib.h>
#include <stdio.h>

pLStack LStack_create(int data) {
    pLStack stack = (pLStack)malloc(sizeof(LStack));
    stack->data = data;
    stack->pnext = NULL;

    return stack;
}

void LStack_destroy(pLStack stack) {
    while (stack) {
        pLStack temp = stack;
        stack = stack->pnext;
        free(temp);
    }
}

void LStack_push(pLStack *stack, int number) {
    pLStack new_node = LStack_create(number);
    new_node->pnext = *stack;
    *stack = new_node;
}

int LStack_pop(pLStack *stack) {
    if (!*stack) 
        return -1; 

    int data = (*stack)->data;
    pLStack temp = *stack;
    *stack = (*stack)->pnext;
    free(temp);

    return data;
}

int LStack_empty(pLStack stack) {
    return stack == NULL;
}

int LStack_full(pLStack stack) {
    return 0; 
}

int LStack_count(pLStack stack) {
    int count = 0;
    while (stack) {
        count++;
        stack = stack->pnext;
    }
    return count;
}


pLQueue LQueue_create(int data) {
    pLQueue que = (pLQueue)malloc(sizeof(LQueue));
    que->data = data;
    que->pprev = que->pnext = que;
    return que;
}

void LQueue_destroy(pLQueue que) {
    pLQueue temp = que->pnext;
    while (temp != que) {
        pLQueue next = temp->pnext;
        free(temp);
        temp = next;
    }
    free(que);
}

void LQueue_put(pLQueue que, int number) {
    pLQueue new_node = LQueue_create(number);
    new_node->pnext = que;
    new_node->pprev = que->pprev;
    que->pprev->pnext = new_node;
    que->pprev = new_node;
}

int LQueue_get(pLQueue *que) {
    if (*que == (*que)->pnext) 
        return -1; 
    int data = (*que)->data;
    pLQueue temp = *que;
    (*que)->pprev->pnext = (*que)->pnext;
    (*que)->pnext->pprev = (*que)->pprev;
    *que = (*que)->pnext;
    free(temp);
    return data;
}

int LQueue_empty(pLQueue que) {
    return que == que->pnext;
}

int LQueue_full(pLQueue que) {
    return 0; 
}

int LQueue_count(pLQueue que) {
    int count = 0;
    pLQueue temp = que->pnext;
    while (temp != que) {
        count++;
        temp = temp->pnext;
    }
    return count;
}