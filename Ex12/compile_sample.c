/* 第12回  条件コンパイルの動作を試すためのサンプルプログラム */
#include <stdio.h>

#define JAPANESE 0

int main()
{
  int i, n, sum=0;

#if JAPANESE
  printf("奇数を入力してください: ");
#else
  printf("Please input an odd number: ");
#endif
  
  scanf("%d", &n);     /* キーボードから入力 */

  for( i=1; i<=n; i+=2 ){   /* 奇数の和を求めるループ */
    sum += i;
    
#ifdef DEBUG
    printf("i = %d,  sum = %d\n", i, sum);
#endif
  }

  /* 結果の出力 */
#if JAPANESE
  printf("1 から %d までの奇数の和", n);
#else
  printf("Sum of odd numbers from 1 to %d", n);
#endif
  printf(" = %d\n", sum);
  
  return 0;
}
