#include <stdio.h>
#include <string.h>

int main()
{
  int i, len;
  int start_pos, end_pos;
  char str1[] = "Undergraduate School and Graduate School";
  char *p, *q;
  
  len = strlen(str1);
  printf("Input start and end positions (1 - %d): ", len);
  scanf("%d%d", &start_pos, &end_pos);

  /* 通常の配列添字を使い、配列の要素を順次参照する方法 */
  for(i = start_pos - 1; i < end_pos; i++) {
    printf("%c", str1[i]);
  }
  printf("\n");
  
  /* 参照するアドレスをポインタ演算で計算する方法。pは固定。 */
  p = str1;
  for(i = start_pos - 1; i < end_pos; i++) {
    printf("%c", *(p + i));
  }
  printf("\n");

  /* ポインタ変数に格納されているアドレスそのものを変えていく方法 */
  for(q = str1 + start_pos - 1; q < str1 + end_pos; q++) {
    printf("%c", *q);
  }
  printf("\n");
  return 0;
}