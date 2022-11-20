#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define NMAX 20     /* 1日の最大バス本数 */
#define NSTOP 6     /* バス停留所数 */
#define UNDEF -999  /* バスが停車しない時を表すダミー値 */
 
typedef struct{
	char colstr1[8];        /* カラム1（番号） */
	char colstr2[8];        /* カラム2（会社名） */
	char bsname[NSTOP][12]; /* バスの停留所名 */
}Tableinfo;
 
typedef struct{
	int number;      /* バス番号 */
	char company[8]; /* 会社名 */
	int hour[NSTOP]; /* 時間 */
	int min[NSTOP];  /* 分 */
}Businfo;

void printInfo(Businfo, Tableinfo); /* 結果表示用関数 */

int main(int argc, char *argv[]){
  int i, j, k, nbus, nstop;
  char buf[256];
  char query_bus[12];
  int query_from, query_to;
  Tableinfo table;
  Businfo bus[NMAX];
  FILE *fp;
  
  /* ファイルを開く */
  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "ファイルを開けませんでした\n");
    exit(1);
  }

  fscanf(fp, "%s %s");
  for(i = 0; i < NSTOP; i++){
    fscanf(fp, "%s", table.bsname[i]);
  }

  for(i = 0; i < NMAX; i++){
    if(fscanf(fp, "%s %s", &bus[i].number, &bus[i].company) == EOF)
      break;
    for(j = 0; j < NSTOP; j++){
      fscanf(fp, "%d:%d", &bus[i].hour[j], &bus[i].min[j]);
    }
  }
  fclose(fp);

  /*標準入力から停留所名と時間帯（6 時台から 12 時台など。分単位は無視）を入力し、 
  その停留所に指定した時間帯に停車するバスの時刻情報を表示する
  （通過する停留所の情報は省略する）。 表示は関数を作成してよび出すことで行う。
  */
  printf("Input the name of bus stop.\n");
  scanf("%s", query_bus);
  printf("Hours from/to?\n");
  scanf("%d %d", &query_from, &query_to);

  for(i = 0; i < )

      return 0;
}





 
