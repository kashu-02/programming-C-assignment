#include <stdio.h>

char VowelChgCase(char);

int main(){
  int status;
  char c;

  while(1){
    status = scanf("%c", &c);
    if(status == -1){
      break;
    }
    printf("%c", VowelChgCase(c));
  }
  return 0;
}

char VowelChgCase(char c){
  if(!(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')) return c;
  if(c >= 'a' && c <= 'z'){
    return c -= 32;
  }else if(c >= 'A' && c <= 'Z'){
    return c += 32;
  }
}