#include <stdio.h>
#include <string.h>

#define NWORD 6

int main()
{
  char str2[NWORD][20];   /* 入力用の文字配列 */
  char newstr[120];       /* 出力用の文字配列 */
  int i;
  /* ここにその他の変数宣言 */

  printf( "Input %d words: \n", NWORD );

  for( i = 0; i < NWORD; i++ ){
    /* ここに入力された単語をstr2に読み込む処理を書く */
    scanf( "%s", str2[i] );
  }

  /* 入力されたstr2をもとに、newstrを作成する処理を書く */
  /* 単語の間にスペースを入れながら、各単語をつないだ一つの文字列にする */
  for (i = 0; i < NWORD; i++) {
    if(i == 0) strcpy(newstr, str2[i]);
    if(i > 0) strcat(newstr, str2[i]);
    if(i < NWORD - 1) strcat(newstr, " ");
  }

    printf("%s\n", newstr); /* 新しい文字列全体を表示 */

  /* ここで、newstrの文字数を表示 */
  printf("Total: %d characters\n", strlen(newstr));

  return 0;
}