#include <stdio.h>
 
#define N 258 /* ??? にはバッファ配列に最大文字数の文字列を適切に格納可能な数値を指定する */
 
int main(){
	char str[N], str_new[N];
	
	/* 適宜変数を追加すること */
  int i;
  char c;
	
	printf("Input : ");
	scanf("%s", str); /* 文字列を標準入力から入力 */
	
	/*
	 * 最初の開括弧 ( を代入し
	 * 入力した文字列を1文字ずつチェックし，
	 * 英数字（すなわち0-9, A-Z, a-z）ならそのまま str_new にコピー，
	 * それ以外なら str_new に'_'を代入する，
	 * さらに，最後の閉括弧 ) を代入し，
	 * str_new の末尾の処理（ヌル文字）が必要となる
	 */

  str_new[0] = '(';
  for(i = 0; i < 256; i++){
    if(str[i] == '\0') break;
    if((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')){
      str_new[i + 1] = str[i];
    }else{
      str_new[i + 1] = '_';
    }
  }
  str_new[i + 1] = ')';
  str_new[i + 2] = '\0';





	
	printf("Before : %s\n", str);
	printf("After  : %s\n", str_new);
	
	return 0;
}