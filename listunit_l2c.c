#include "listunit_l2c.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pnodeL2C createNodeL2C(double data) {
    pnodeL2C p = (pnodeL2C)malloc(sizeof(tnodeL2C));

    p->data = data;
    p->pprev = p->pnext = p;
    return p;
}

pnodeL2C addFirstNodeL2C(pnodeL2C *ph, pnodeL2C p) {
    if (*ph == NULL) {
        *ph = p;
    } else {
        p->pnext = *ph;
        p->pprev = (*ph)->pprev;
        (*ph)->pprev->pnext = p;
        (*ph)->pprev = p;
        *ph = p;
    }
    return p;
}

pnodeL2C addLastNodeL2C(pnodeL2C *ph, pnodeL2C p) {
    if (*ph == NULL) {
        *ph = p;
    } else {
        p->pnext = *ph;
        p->pprev = (*ph)->pprev;
        (*ph)->pprev->pnext = p;
        (*ph)->pprev = p;
    }
    return p;
}

pnodeL2C insertAfterNodeL2C(pnodeL2C pn, pnodeL2C p) {
    p->pprev = pn;
    p->pnext = pn->pnext;
    pn->pnext->pprev = p;
    pn->pnext = p;
    return p;
}

pnodeL2C insertBeforeNodeL2C(pnodeL2C pn, pnodeL2C p) {
    p->pprev = pn->pprev;
    p->pnext = pn;
    pn->pprev->pnext = p;
    pn->pprev = p;
    return p;
}

pnodeL2C deleteNodeL2C(pnodeL2C *ph, pnodeL2C pn) {
    if (*ph == pn) {
        *ph = pn->pnext;
    }
    pn->pprev->pnext = pn->pnext;
    pn->pnext->pprev = pn->pprev;
    return pn;
}

void disposeNodeL2C(pnodeL2C *pn) {
    if (*pn != NULL) {
        if ((*pn)->pnext == *pn) {
            free(*pn);
        } 
		else {
            (*pn)->pprev->pnext = (*pn)->pnext;
            (*pn)->pnext->pprev = (*pn)->pprev;
            free(*pn);
        }
    }
}

void disposeListL2C(pnodeL2C *ph) {
    if (*ph == NULL) {
        return;
    }
    pnodeL2C current = *ph;
    pnodeL2C next;

    do {
        next = current->pnext;
        free(current);
        current = next;
    } 
	while (current != *ph);
    *ph = NULL;
}

void listActionL2C(pnodeL2C ph, int fwd, listfunc func) {
    if (ph == NULL) {
        return;
    }
    pnodeL2C curr = fwd ? ph : ph->pprev;
    do {
        if (func(curr->data) == 0) {
            return;
        }
        curr = fwd ? curr->pnext : curr->pprev;
    } while (curr != ph);
}

//
int printDouble(double data) {
    printf("data: %lf\n", data);
    return 1;
}
//

void listOutL2C(pnodeL2C ph, int fwd) {
    listActionL2C(ph, fwd, printDouble);
}

//
int count = 0;
int incrementCount(double data) {
    count++;
    return 1; 
}
//

int listCountL2C(pnodeL2C ph) {
	listActionL2C(ph, 1, incrementCount);
    return count;
}

double minmaxL2C(pnodeL2C ph, int min) {
    if (ph == NULL) {
        return 0;
    }
    pnodeL2C current = ph->pnext;
    double result = ph->data;

    if (min) {
        while (current != ph) {
            if (current->data < result) {
                result = current->data;
            }
            current = current->pnext;
        }
    } else {
        while (current != ph) {
            if (current->data > result) {
                result = current->data;
            }
            current = current->pnext;
        }
    }
    return result;
}

pnodeL2C AboveNodeL2C(pnodeL2C ph, int first, double data) {
    if (ph == NULL) {
        return NULL;
    }
    pnodeL2C current = ph;

    do {
        if (first) {
            if (current->data > data) {
                return current;
            }
            current = current->pnext;
        } else {
            current = current->pprev;
            if (current->data > data) {
                return current;
            }
        }
    } while (current != ph);
    return NULL;
}

pnodeL2C BelowNodeL2C(pnodeL2C ph, int first, double data) {
    if (ph == NULL) {
        return NULL;
    }
    pnodeL2C current = ph;

    do {
        if (first) {
            if (current->data < data) {
                return current;
            }
            current = current->pnext;
        } else {
            current = current->pprev;
            if (current->data < data) {
                return current;
            }
        }
    } while (current != ph);
    return NULL;
}
