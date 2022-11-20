#include <stdio.h>
#include <stdlib.h>
 
#define MAX_W 256       /* 画像の幅の最大 */
#define MAX_H 256       /* 画像の高さの最大 */
#define BUF 256         /* バッファサイズ */
 
/* 画像の幅，高さ，画素値を格納する外部変数 */
int w, h, i_img[MAX_W * MAX_H], o_img[MAX_W * MAX_H];
 
int read();
void write();
void superpose();
 
int main(){
	superpose();
	write();
	return 0;
}
 
/*
 * 入力されたファイル名の Plain PBM 形式画像ファイルを読み込み，
 * その幅，高さ，画素値をそれぞれ外部変数 w, h, i_img に格納する
 */
int read(){
	FILE *fp;
	char filename[BUF];
	int r;
  int i;
	
	/* 必要に応じて変数宣言を追加 */
	
	printf("ファイル名を入力してください: ");
	
	if((r = scanf("%s", filename)) == EOF)
		return EOF;
		
	if((fp = fopen(filename, "r")) == NULL){
		fprintf(stderr, "ファイル %s を開けません！\n", filename);
		exit(1);
	}
	
	/* 仕様にしたがって関数を作成しなさい */
  if(getc(fp) != 'P' || getc(fp) != '1') {
    fprintf(stderr, "ファイル %s は PBM 形式ではありません！\n", filename);
    exit(2);
  }

  fscanf(fp, "%d %d", &w, &h);

  if(w > MAX_W || h > MAX_H) {
    fprintf(stderr, "ファイル %s の画像サイズが大きすぎます！\n", filename);
    exit(3);
  }

  for(i = 0; i < w * h; i++) {
    fscanf(fp, "%d", &i_img[i]);
  }

  fclose(fp);

  return r;
}
 
/*
 * 外部変数 w(幅)，h(高さ)，o_img(画素値) で与えられる画像を，
 * Plain PBM 形式でファイル out.pbm に書き出す
 */
void write(){
	/* 仕様にしたがって関数を作成しなさい */
  FILE *fp;
  int i;
  fp = fopen("out.pbm", "w");
  fprintf(fp, "P1\n");
  fprintf(fp, "%d %d\n", w, h);
  for(i = 0; i < w * h; i++) {
    if(i + 1 % w == 0) {
      fprintf(fp, "\n");
    }
    fprintf(fp, "%d ", o_img[i]);
  }

  fclose(fp);
}
 
/*
 * 画像ファイルを read 関数を用いて読み込み，
 * それらを重ね合わせてできる画像の画素値を
 * 外部変数 o_img に格納する
 */
void superpose(){
	/* 仕様にしたがって関数を作成しなさい */
  int i, w1 = 0, h1 = 0;
  for(i = 0; i < MAX_W * MAX_H; i++){
    o_img[i] = 0;
  }

  while(read() != EOF){
    if((w1 != 0 && h1 != 0) && (w1 != w || h1 != h) ){
      fprintf(stderr, "画像サイズが異なっています！\n");
      exit(4);
    }
    w1 = w;
    h1 = h;
    printf("width = %d, height = %d\n", w1, h1);
    for (i = 0; i < w * h; i++){
      o_img[i] = i_img[i] | o_img[i]; //ビット演算OR
    }
  }
}