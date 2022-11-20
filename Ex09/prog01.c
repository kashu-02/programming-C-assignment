#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stulist01.h"

int main()
{
  int i;
  Record data;
  data.id = 0;
  head = make_1node(&data, NULL);
  listprint();

  while (1) {
    printf("Insert new data:(class ID name)-> ");
    if(scanf("%s %d %s %s", data.class, &data.id, data.surname, data.givenname) != 4)
      break;
    if (insert(&data) == NULL)
      printf("ID %d is already on the list\n", data.id);
    listprint();
  }
  printf("\n");
  return 0;
}

NodePointer insert(Record *data)
{
  NodePointer newnode;

  if (finditem(data->id) == NULL) {
    newnode = make_1node(data, head->next);
    head->next = newnode;

    return newnode;
  }
  else return NULL;
}

void listprint(void)
{
  NodePointer n;

  printf("Head -\n");
  for (n = head->next; n != NULL; n = n->next) {
    printf("\t%s %d %s %s\n", n->key.class, n->key.id, n->key.surname, n->key.givenname);
  }
  printf("\n");
}

NodePointer finditem(int id)
{
  NodePointer n;

  for (n = head; n->next != NULL; n = n->next) {
    if (n->next->key.id == id) return n;
  }

  return NULL;
}

NodePointer make_1node(Record *data, NodePointer p)
{
  NodePointer n;

  if ((n = (NodePointer)malloc(sizeof(struct node))) == NULL) {
    printf("Error in memory allocation\n");
    exit(8);
  }

  n->key.id = data->id;
  strcpy(n->key.class, data->class);
  strcpy(n->key.surname, data->surname);
  strcpy(n->key.givenname, data->givenname);
  n->next = p;

  return n;
}
