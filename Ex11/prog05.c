#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rsrch(char *, char *);

int main(){
  char query[100], word[1000];
  int result;
  FILE *fp;

  fp = fopen("/usr/share/dict/words", "r");

  printf("Enter string to search for : ");
  scanf("%s", query);

  while(fscanf(fp, "%s", word[100]) != EOF){
    if(strlen(word) < strlen(query)) continue;
    if(strlen(word) > strlen(query)){
      result = rsrch(word[strlen(word) - strlen(query)], query);
    }else{
      result = rsrch(word, query);
    }
    
  }





}

int rsrch(char *word, char *query){
  int i;

  for(i = strlen(query) - 1; i >= 0; i--){
    if(word[i] != query[i]) return 0;
  }
  return 1;
}