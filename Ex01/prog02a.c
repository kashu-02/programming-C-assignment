#include <stdio.h>

#define TRUE 1
#define FALSE 0

int isAlpha(char);

int main(){ 
  char c;
  
  printf("Input a characters: ");
  while(1){
    scanf("%c",&c);
    if(c == '\n') break;
    printf("ASCII code of '%c' is %d(0x%x).",c,c,c);
    if(isAlpha(c) == FALSE) printf(" It's a non-alphabetic character.");
    else printf(" It's an alphabetic character.");
    printf("\n");
  }
  return 0;
}

int isAlpha(char c){
  if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return TRUE;
  else return FALSE;
}