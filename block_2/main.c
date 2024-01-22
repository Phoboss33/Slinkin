#include <stdio.h>
#include "squnitL.h"

int main() {
    pLStack stack;
    pLQueue queue;
    int num;

    stack = LStack_create(10); // создать стек
    LStack_push(&stack, 20); // поместить элемент на вершину стека
    num = LStack_pop(&stack); // вернуть элемент с вершины стека
    printf("Num: %d\n", num);
    num = LStack_empty(stack); // проверить на пустоту стека
    printf("Empty: %d\n", num);
    num = LStack_full(stack); // проверить на полноту стека
    printf("Full: %d\n", num);
    num = LStack_count(stack); // вернуть количество элементов в стеке
    printf("Count: %d\n", num);
    LStack_destroy(stack); // уничтожить стек

    printf("=====\n");
    queue = LQueue_create(10); // создать очередь
    LQueue_put(queue, 20); // поместить элемент в конец очереди
    num = LQueue_get(&queue); // вернуть элемент из начала очереди
    printf("Num: %d\n", num);
    num = LQueue_empty(queue); // проверить на пустоту очереди
    printf("Empty: %d\n", num);
    num = LQueue_full(queue); // проверить на полноту очереди
    printf("Full: %d\n", num);
    num = LQueue_count(queue); // вернуть количество элементов в очереди
    printf("Count: %d\n", num);
    LQueue_destroy(queue); // уничтожить очередь
    return 0;
}
