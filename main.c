#include <stdio.h>
#include "listunit_l1.h"

int printNode(char *data) {
  printf("%s ", data);
  return 1;
}

int main()
{
  pnodeL1 head = NULL;
  pnodeL1 currentNode = NULL;
  unsigned char dest[255] = "";

  head = createNodeL1("1"); 

  currentNode = addFirstNodeL1(&head, createNodeL1("2"));
  printf("Добавлен в начало: %s\n", currentNode->data);

  currentNode = addLastNodeL1(&head, createNodeL1("Слово"));
  printf("Добавлен в конец: %s\n", currentNode->data);

  currentNode = insertAfterNodeL1(head->pnext->pnext, createNodeL1("33"));
  printf("Вставлен после нода %s\n", currentNode->data);

  int count = listCountL1(head);
  printf("Всего %d элементов: \n", count);

  listSumStr(dest, 255, head, ", ");
  printf("Объединение: %s\n", dest);

  printf("listActionL1: ");
  listActionL1(head, printNode);
  printf("\n");

  printf("Список: \n");
  listOutL1(head);
  printf("\n");

  disposeAfterNodeL1(head->pnext); 
  printf("Список: \n");
  listOutL1(head);
  printf("\n");
  disposeListL1(&head);

  printf("Список: \n");
  listOutL1(head);
  return 0;
}
