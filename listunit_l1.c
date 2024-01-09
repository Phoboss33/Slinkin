#include "listunit_l1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pnodeL1 createNodeL1(char *data)
{
    pnodeL1 p = (pnodeL1)malloc(sizeof(tnodeL1));
    p->data = data;  
    p->pnext = NULL;
    return p;
}

 pnodeL1 addFirstNodeL1(pnodeL1 *ph, pnodeL1 p)
 {
    p->pnext = *ph;
    *ph = p;
    return p;
 }

 pnodeL1 addLastNodeL1(pnodeL1 *ph, pnodeL1 p)
 {
    if (*ph == NULL) {
        *ph = p;
    }
    else {
        pnodeL1 curNode = *ph;
        while (curNode->pnext != NULL) {
            curNode = curNode->pnext;
        }
        curNode->pnext = p;
    }
    return p;
 }

 pnodeL1 insertAfterNodeL1(pnodeL1 pn, pnodeL1 p)
 {
    p->pnext = pn->pnext;
    pn->pnext = p;
    return p;
 }

void disposeNodeL1(pnodeL1 *pn) {
    if (*pn != NULL) {
        pnodeL1 currentNode = *pn;
        
        *pn = currentNode->pnext;
        free(currentNode);
        currentNode = NULL;
    } 
}

pnodeL1 deleteAfterNodeL1(pnodeL1 pn) {
    if (pn != NULL && pn->pnext != NULL) {
        pnodeL1 deleteNode = pn->pnext;

        pn->pnext = deleteNode->pnext;
        deleteNode->pnext = NULL;

        return deleteNode;
    }
    return NULL;
}

 void disposeAfterNodeL1(pnodeL1 pn)
 {
    if (pn != NULL && pn->pnext != NULL) {
        pnodeL1 deletedNode = pn->pnext;
        pn->pnext = deletedNode->pnext;
        
        free(deletedNode);
    }
 }

	 void disposeListL1(pnodeL1 *ph)
	 {
		while (*ph != NULL) {
			pnodeL1 next = (*ph)->pnext;
			(*ph)->pnext = NULL;  
			free(*ph);
			*ph = next;
		}
	 }

 void listActionL1(pnodeL1 ph, listfunc func)
 {
    pnodeL1 cur = ph;
    while (cur != NULL) {
        if (func(cur->data) == 0) {
            break;
        }
        cur = cur->pnext;
    }
 }

 void listOutL1(pnodeL1 ph)
 {
    pnodeL1 cur = ph;
    while (cur != NULL) {
        printf("data: [%s]\n", cur->data);
        cur = cur->pnext;
    }
 }

 int listCountL1(pnodeL1 ph) 
 {
    int count = 0;
    pnodeL1 cur = ph;
    while (cur != NULL) {
        count++;
        cur = cur->pnext;
    }
    return count;
 }

// объединение по байтам
// в конце не должно быть запятой
char *listSumStr(char *dest, int maxsize, pnodeL1 ph, char *delimiter)
{
    pnodeL1 current = ph;
    int count = 0;

    while (count < maxsize) {
        if (current != NULL) {
            strncat(dest, current->data, maxsize - 1);
            count += strlen(current->data);
            if (count < maxsize - 1) {
                strcat(dest, delimiter);
                count++;
            }
            current = current->pnext;
        } 
        else {
            return dest;
        }
    }
    return NULL;
}
