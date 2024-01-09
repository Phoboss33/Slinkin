#include <stdio.h>
#include "listunit_l1.h"

int i = 1;


int printNode(char *data) {
	if (i == 0) {
		printf("%s ", data);
		return 1;
	}
	else 
		return 0;

}

int main()
{
  pnodeL1 head = NULL;
  pnodeL1 currentNode = NULL;
  char dest[255] = "";

  head = createNodeL1("1"); 



  currentNode = addFirstNodeL1(&head, createNodeL1("23"));
  printf("Добавлен в начало: %s\n", currentNode->data);

  currentNode = addLastNodeL1(&head, createNodeL1("slovo"));
  printf("Добавлен в конец: %s\n", currentNode->data);

  //currentNode = insertAfterNodeL1(head->pnext, createNodeL1("33"));
  //printf("Вставлен после нода %s\n", currentNode->data);

  listOutL1(head);
  printf("\n");
  //disposeNodeL1(&head);
  
  //currentNode = deleteAfterNodeL1(head);
  //printf("deleteAfterNodeL1 %s\n", currentNode->data);
  
  //disposeAfterNodeL1(head); 

  
  //printf("listActionL1: ");
  //listActionL1(head, printNode);
  //printf("\n");
  
  //int count = listCountL1(head);
  //printf("Всего %d элементов: \n", count);

  listSumStr(dest, 5, head, "<><><><><><><><>");
  printf("Объединение: %s\n", dest);



  //printf("Список: \n");
  //listOutL1(head);
  //printf("\n");

  //disposeAfterNodeL1(head->pnext); 
  //printf("Список: \n");
  //listOutL1(head);
  //printf("\n");
  

  //printf("Список: \n");
  listOutL1(head);
  
  disposeListL1(&head);
  
  
  return 0;
}
