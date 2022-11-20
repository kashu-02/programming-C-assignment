#include <stdio.h>

int main(){ 
  char c;
  
  printf("Input a characters: ");
  while(1){
    scanf("%c",&c);
    if(c == '\n') break;
    printf("ASCII code of '%c' is %d(0x%x).\n",c,c,c);
  }
  return 0;
}