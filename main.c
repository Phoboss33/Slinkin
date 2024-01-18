#include <stdio.h>
#include <stdlib.h>
#include "listunit_l2c.h"

int func(double data) {
    printf("Func: %lf\n", data);
    return 0;
}

int main() {
    pnodeL2C list = NULL;
    pnodeL2C current = NULL;
    int count;
    double minMax;

    // создать узел и вернуть его
    // вставить узел в начало списка и вернуть его
    //printf("Current: %lf\n", current->data);
    //current = addLastNodeL2C(&list, createNodeL2C(3)); // вставить узел в конец списка и вернуть его
    //printf("Current: %lf\n", current->data);
    //current = insertAfterNodeL2C(list, createNodeL2C(4)); // вставить и вернуть узел после переданного узла
    //printf("Current: %lf\n", current->data);
    //current = insertBeforeNodeL2C(list, createNodeL2C(5)); // вставить и вернуть узел перед переданного узла
    //list = current; // включить, если передаём голову списка
    //printf("Current: %lf\n", current->data);
     // удалить и вернуть узел из списка
    
    //current = list->pnext;
     // уничтожить узел и установить его в NULL
    //disposeListL2C(&list); // уничтожить список и установить его в NULL
    //listActionL2C(list, 1, func); // выполнить функцию func над каждым узлом списка
    /*listOutL2C(list, 1); // вывод списка в прямом (fwd != 0) или обратном (fwd == 0) порядке


    current = AboveNodeL2C(list, 1, 0); // вернуть первый (first != 0) или последний (first == 0) элемент в списке, больший data
    if (current != NULL) {
        printf("Current: %lf\n", current->data);
    } else {
        printf("Current: NO\n");
    }
    current = BelowNodeL2C(list, 1, 4); // вернуть первый (first != 0) или последний (first == 0) элемент в списке, меньший data
    if (current != NULL) {
        printf("Current: %lf\n", current->data);
    } else {
        printf("Current: NO\n");
    }*/


    list = createNodeL2C(1); 
    current = addFirstNodeL2C(&list, createNodeL2C(2)); 
    current = addFirstNodeL2C(&list, createNodeL2C(3)); 
    listActionL2C(list, 0, func);
    current = deleteNodeL2C(&list, list->pnext);
    printf("Current: %lf\n", current->data);
    disposeNodeL2C(&current);

    listOutL2C(list, 1); 

    minMax = minmaxL2C(list, 5); // вернуть минимальный (min != 0) или максимальный (min == 0) элемент в списке
    printf("MinMax: %lf\n", minMax);

    count = listCountL2C(list); // вернуть количество элементов в списке
    printf("Count: %d\n", count);
    disposeListL2C(&list);
    return 0;
}
