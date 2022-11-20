#include <stdio.h>
#include <stdlib.h>
/* 数学関数を使いたい場合は以下のコメントを外す */
/* #include <math.h> */
 
/* マクロ定義 */
#define N 256 /* 画像サイズ */
#define RD 64 /* 円盤の半径 */
#define BLACK '1'
#define WHITE '0'
 
/* 構造体宣言 */
typedef struct{
	int x;
	int y;
}XYdata;
 
/* 関数のプロトタイプ宣言 */
void init(void);
void imgout(void);
void circle(XYdata);
void init(void);

/* 画像の各ドットを表す外部変数の定義 */
char data[N][N];
 
int main(int argc, char *argv[]){
	XYdata cent;
	int ncent, i;
	
	/* コマンドラインから円の中心座標を何組か入力される */
	
	/* 入力された中心座標が何組あるか計算 */
  ncent = (argc - 1) / 2;

  /* 画像初期化関数(すべて白くする)をよぶ */
  init();

	
	/* 座標の組の数だけ繰り返す */
  for (i = 0; i < ncent; i++) {
    cent.x = atoi(argv[2 * i + 1]);
    cent.y = atoi(argv[2 * i + 2]);
    /* 円の内部を白黒反転する */
		circle(cent);
  }
	
	/* 表示 */
	imgout();
	
	return 0;
}
 
/* すべての点を白に初期化する関数 */
void init(void){
  int i, j;
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      data[i][j] = WHITE;
    }
  }
}
 
/* 引数で指示された座標の点一つを白黒反転する関数 */
void rev(XYdata a){
  if(data[a.y][a.x] == WHITE){
    data[a.y][a.x] = BLACK;
  }else{
    data[a.y][a.x] = WHITE;
  }
}
 
/* 引数で指示された座標を中心に，半径 RD 以内の点を白黒反転する関数 */
void circle(XYdata c){
  int i, j;
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      if((i - c.y) * (i - c.y) + (j - c.x) * (j - c.x) <= RD * RD){
        rev((XYdata){j, i});
      }
    }
  }
}
 
/* Plain PBM形式で画像データを出力する関数 */
void imgout(void){
  int i, j;
  printf("P1\n");
  printf("%d %d\n", N, N);
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      printf("%c ", data[i][j]);
    }
    printf("\n");
  }
 
}