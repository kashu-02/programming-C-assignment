#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stulist04.h"

int main(int argv, char *argc[])
{
  int i;
  char order;
  Record data;
  FILE *fp;
  data.id = 0;
  head = make_1node(&data, NULL);
  if(argv == 2){
    fp = fopen(argc[1], "r");
  }
  if(argv != 2 || fp == NULL){
    fp = fopen("/home/course/prog1/public_html/2022/ex/ex09/Student.dat", "r");
  }

  printf("Enter sort mode (d:descending / a:ascending) -> ");
  scanf("%c", &order);

  while (fscanf(fp, "%s %d %s %s", data.class, &data.id, data.surname, data.givenname) != EOF)
    insert_sort(&data, order);
  fclose(fp);

  listprint();

  while (1) {
    printf("Insert new data:(class ID name)-> ");
    if(scanf("%s %d %s %s", data.class, &data.id, data.surname, data.givenname) != 4)
      break;
    if (insert_sort(&data, order) == NULL)
      printf("ID %d is already on the list\n", data.id);
    listprint();
  }
  printf("\n");
  return 0;
}

NodePointer insert(Record *data)
{
  NodePointer newnode, lastNode;

  if (finditem(data->id) == NULL) {
    for (lastNode = head; lastNode != NULL; lastNode = lastNode->next){
      if(lastNode->next == NULL)
        break;
    };
    newnode = make_1node(data, NULL);
    lastNode->next = newnode;

    return newnode;
  }
  else return NULL;
}

NodePointer insert_sort(Record *data, char order){
  NodePointer newnode, lastNode;

  if (finditem(data->id) != NULL)
    return NULL;
  for (lastNode = head; lastNode != NULL; lastNode = lastNode->next)
  {
    if((lastNode->next == NULL || lastNode->next->key.id > data->id) && order == 'a') break;
    if((lastNode->next == NULL || lastNode->next->key.id < data->id) && order == 'd') break;
  };
  if(lastNode->next == NULL){
    newnode = make_1node(data, NULL);
  }else{
    newnode = make_1node(data, lastNode->next);
  }
  lastNode->next = newnode;

  return newnode;
}

void listprint(void)
{
  NodePointer n;
  int i = 0;
  printf("Head -\n");
  for (n = head->next; n != NULL; n = n->next) {
    printf("\t%s %d %s %s\n", n->key.class, n->key.id, n->key.surname, n->key.givenname);
    i++;
  }
  printf("%d nodes exist in the list.\n", i);
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
