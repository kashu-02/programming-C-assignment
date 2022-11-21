#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDS 5

int main()
{
  int i,j,word_length;
  char word[100], *arr[WORDS];

  for(i = 0; i < WORDS; i++){
    printf("Input word #%d: ", i + 1); 
    scanf("%s",&word);
    arr[i] = (char*) malloc(sizeof(char) * strlen(word));
    strcpy(arr[i], word);
  }

  for(i = 0; i < WORDS; i++){
    printf("Word #%d (Length: %d): %s\n", i+1, strlen(arr[i]), arr[i]);
  }
  
  for(i = 0; i < WORDS; i++) free(arr[i]);

  return 0;
}
