#include <stdio.h>
 
int myatoi(char *);
 
int main()
{
  char str2[][20]={ "  2022",
                    " -60.50",
                    "+32m",
                    " 999,654",
                    "+-24",
                    "x86",
                    "2022/11/30",
                    ""};
  int ival, i;
 
  for ( i=0; str2[i][0]!='\0'; i++ ){
    ival = myatoi( str2[i] );
    printf("string:%s\n", str2[i]);
    printf("value:%d\n", ival);
  }
  return 0;
}
/* この後に関数 myatoi を作成する */

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