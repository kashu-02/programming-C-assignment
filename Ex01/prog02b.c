#include <stdio.h>

#define TRUE 1
#define FALSE 0

int isAlpha(char);
int isUpper(char);

int main(){ 
  char c;
  
  printf("Input a characters: ");
  while(1){
    scanf("%c",&c);
    if(c == '\n') break;
    printf("ASCII code of '%c' is %d(0x%x).",c,c,c);
    if(isAlpha(c) == FALSE){
      printf(" It's a non-alphabetic character.");
    } else{
      if(isUpper(c) == TRUE){
        printf(" It's an upper case character.");
      } else{
        printf(" It's a lower case character.");
      }
    }
    printf("\n");
  }
  return 0;
}

int isAlpha(char c){
  if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
    return TRUE;
  } else{
    return FALSE;
  }
}

int isUpper(char c){
  if(c >= 'A' && c <= 'Z'){
    return TRUE;
  } else{
    return FALSE;
  }
}