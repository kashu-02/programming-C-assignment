#include <stdio.h>
#define N 10

typedef struct {
  int map[N][N];
  int step; /* 各経路上で通った順番を表す変数 */ 
  int msize, nsize;
} SMAP;

void routing(int, int, SMAP);
void mapprint(SMAP);

int pat = 0; /* ゴールに到達したパターン数を記録するための外部変数 */

int main()
{
  SMAP smap;
  int i, j;

  printf("マスのサイズを入力して下さい(msize, nsize):\n");
  scanf("%d%d", &smap.msize, &smap.nsize);

  /* smapの初期化 */
  for ( i=0 ; i<N ; i++ )
    for ( j=0 ; j<N ; j++ )
      smap.map[i][j] = 0;
  smap.step = 1;

  routing(smap.msize-1, smap.nsize-1, smap); /* msize-1, nsize-1から探索開始 */

  return 0;
}

void routing(int m, int n, SMAP smap)
{
 /* まず m, n がマップ（マス）外なら即 return */
  /* m, n が 0, 0 ならゴールなので、pat++し、マップを表示して、return */
  /* マップの m, n の位置が0でない（既に通った）なら、何もせずにreturn */
  /* マップの m, n の位置が0なら step（通ったマスの順番）を代入し、step++ */
  /* m, n の周辺４方向について、再度 routing を呼び出す */
  /* 注）一般に配列は[縦][横]で使いますが、 m, n はマスの
  　　　 横、縦を表すので、整合性に注意して下さい */

  /*************************
      ここを作成
  **************************/
 if (m > smap.msize || n > smap.nsize)
   return;

 if(m == 0 && n == 0){
  pat++;
  mapprint(smap);
 }
 if(smap.map[m][n] != 0) return;
 if(smap.map[m][n] == 0){
   smap.map[m][n] == smap.step++;
 }
 
 routing(--m, n, smap);
 routing(m, --n, smap);
 routing(++m, n, smap);
 routing(m, ++n, smap);
}

void mapprint(SMAP smap)
{
  /*************************
      ここを作成
  **************************/
  int i, j;
  printf("パターン: %d, 経路長: %d\n", pat, smap.step);
  for(i = 0; i < smap.nsize; i++){
    for (j = 0; j < smap.msize; j++)
    {
      if(smap.map[i][j] != 0){
        printf("%d ", smap.map[i][j]);
      }else{
        printf(". ");
      }
    }
    printf("\n");
  }
}