#include <stdio.h>
#include <stdlib.h>
#include "listunit_l2c.h"

int out(double data) {
    printf("<func data: [%lf]>\n", data);
    return 1;
}

int main() {
    pnodeL2C list = NULL;
    pnodeL2C current = NULL;

    list = createNodeL2C(55); 
    current = addFirstNodeL2C(&list, createNodeL2C(22));
    current = addLastNodeL2C(&list, createNodeL2C(33));
    current = insertAfterNodeL2C(list, createNodeL2C(444));
    current = insertBeforeNodeL2C(list, createNodeL2C(5));

    current = deleteNodeL2C(&list, list->pnext);
    printf("<удален узел с data: [%lf]>\n", current->data);
    current = addLastNodeL2C(&list, current);
    //current = list->pnext;
    disposeNodeL2C(&current);
    
    //printf("CURRENT: [%p]", current);
    //printf("list: [%p]", list->pnext);

    listActionL2C(list, 1, out);
    listOutL2C(list, 1);
    printf("Count: %d\n", listCountL2C(list));

    printf("minmax %ld\n",minmaxL2C(list, 5));
    current = AboveNodeL2C(list, 1, 0);
    current = BelowNodeL2C(list, 1, 4);
    
    disposeListL2C(&list);
    return 0;
}
