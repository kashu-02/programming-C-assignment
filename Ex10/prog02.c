#include <stdio.h>
#include <stdlib.h>

int myatoi(char *);

int main(){
  char input[5];
  int base = 0, num;
  printf("和暦（H30, R4等）: ");
  scanf("%s", input);

  if(input[0] == 'R') base = 2019;
  if(input[0] == 'H') base = 1989;
  if(input[0] == 'S') base = 1926;
  if(input[0] == 'T') base = 1912;
  if(input[0] == 'M') base = 1868;
  if(base == 0){
    fprintf(stderr, "元号の文字が変です\n");
    exit(1);
  }
  num = myatoi(&input[1]);
  if(num == 0){
    fprintf(stderr, "数字を読み取れません\n");
    exit(2);
  }

  printf("西暦 (A.D.): %d\n", base + num - 1);

  return 0;
}

int myatoi(char *string){
  
  int i, res = 0, isFirstLetter = 1, isMinus = 0;
  for(i = 0;;i++){
    if ((int)string[i] == 32 && isFirstLetter == 1) // ASCII 32 is whitespace
      continue;
    if((int)string[i] == 45 && isFirstLetter ==1){ //ASCII 45 is minus
      isMinus = 1;
      isFirstLetter = 0;
      continue;
    }
    if((int)string[i] == 43 && isFirstLetter == 1){ //ASCII 43 is plus
      isMinus = 0;
      isFirstLetter = 0;
      continue;
    }
    if((int)string[i] < 48 || (int)string[i] > 57)
      break;
    res *= 10; //shift digit
    res += ((int)string[i] - 48);
    isFirstLetter = 0;
  }
  if(isMinus == 1)
    res *= -1;
  return res;
}