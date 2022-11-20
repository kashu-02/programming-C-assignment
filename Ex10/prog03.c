#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stulist05.h"

int main()
{
  int i;
  Record data;
  FILE *fp;
  data.id = 0;
  head = make_1node(&data, NULL);
  char query[5];

  fp = fopen("Student.dat", "r");

  while(fscanf(fp,"%s %d %s %s", data.class, &data.id, data.surname, data.givenname) != EOF) insert(&data);
  fclose(fp);

  listprint();

  while (1) {
    printf("Input match data (Class or ID) -> ");
    if(scanf("%s", query) != 1)
      break;
    listprint_sel(query);
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

void listprint_sel(char *query){
  char buffer[2000];
  NodePointer n;

  
  if (query[0] > '0' && query[0] < '9')
  {
    for (n = head; n->next != NULL; n = n->next) {
      sprintf(buffer, "%d", n->next->key.id);
      if (strncmp(buffer, query, strlen(query)) == 0)
      {
        printf("\t%s %d %s %s\n", n->next->key.class, n->next->key.id, n->next->key.surname, n->next->key.givenname);
      }
    }
  }else{
    for (n = head; n->next != NULL; n = n->next) {
      if (strcmp(n->next->key.class, query) == 0){
        printf("\t%s %d %s %s\n", n->next->key.class, n->next->key.id, n->next->key.surname, n->next->key.givenname);
      }
    }
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
