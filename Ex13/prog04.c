#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define BLACK '1'
#define WHITE '0'
 
char **pbm_alloc(int, int);
void   pbm_free(char **,int, int);
void   pbm_write(char **, int, int);
char **pbm_read(FILE *, int *x, int *y); /* 要変更 */
char **pbm_dilate(char **pbm, int x, int y);
char **pbm_erode(char **pbm, int x, int y);
//（外部変数は使用しない）
 
int main(int argc, char *argv[])
{
//  （変数宣言）
 FILE *fp;
 int i, argv_length;
 char **pbm;
 int ix, iy;

 //  （コマンドライン解析）
 if (argc == 2 || argc == 3)
 {
   if (argv[1][0] != '-')
   {
     fprintf(stderr, "Error: Invalid operation '%c'\n", argv[1][0]);
     fprintf(stderr, "Usage: ./morph -[ed...] [filename]\n");
     exit(1);
   }
}else{
  fprintf(stderr, "Usage: ./morph -[ed...] [filename]\n");
  exit(1);
}

//  （行うべき処理が指定されていない場合はエラー）
 
//  （ファイルが指定されていない場合はstdinを、それ以外はファイルをopenし
//  　ファイルポインタを得て、pbm_read関数の引数とする）
if(argc == 3){
  if((fp = fopen(argv[2], "r")) == NULL){
    fprintf(stderr, "Error: Cannot open file '%s'\n", argv[2]);
    exit(1);
  }
}else{
  fp = stdin;
}
pbm = pbm_read(fp, &ix, &iy);
if(pbm==NULL){
    fprintf(stderr,"Invalid image format.");
    exit(1);
  }

//  （指定された処理の実行：複数指定された場合は処理の繰返し。
//  　pbm_dilate, pbm_erode関数を繰り返し呼ぶと、メモリの解放が必要になる。）
argv_length = strlen(argv[1]);
if(argv_length != 1){
for(i = 1; i < argv_length; i++){
  if(argv[1][i] == 'e'){
    pbm = pbm_erode(pbm, ix, iy);
  }else if(argv[1][i] == 'd'){
    pbm = pbm_dilate(pbm, ix, iy);
  }else{
    fprintf(stderr, "Error: Invalid operation '%c'\n", argv[1][i]);
    pbm_free(pbm, ix, iy);
    exit(1);
  }
}
}
 
//  （最後に結果の出力）
 pbm_write(pbm, ix, iy);
//  （メモリの解放）
 pbm_free(pbm, ix, iy);
  return 0;
}
 
//（各関数の記述）

/********************************************/
/* 画像データ用の2次元配列確保              */
/* x, y: 確保する2次元配列の大きさ          */
/********************************************/
char **pbm_alloc(int x, int y) {
	char **data;
	int i;
	/* この関数は未完成であり、問題2の完成対象である */
	if((data = (char **)malloc(sizeof(char *) * y)) == NULL){
		free(data);
		return NULL;
	}
	for(i = 0; i < y; i++){
		if((data[i] = (char *)malloc(sizeof(char) * x)) == NULL){
			pbm_free(data, x, y);
			return NULL;
		}
	}


	return data;
}

void  pbm_free(char **pbm, int x, int y) {
/* この関数は完成している */
	int i;
	for (i = 0; i<y; i++)
		free(pbm[i]);
	free(pbm);
}

void   pbm_write(char **pbm, int x, int y) {
/* この関数は完成している */
	int i, j;
	/* 最初にP1とx,yの画素数を出力 */
	printf("P1\n");
	printf("%d %d\n", x, y);
	/* 実際のデータ出力 */
	for (i = 0; i < y; i++) {
		for (j = 0; j < x; j++) {
			printf("%c ", pbm[i][j]);
		}
		printf("\n");
	}
}

/********************************************/
/* 画像データの読み込み                     */
/* x, y: 画像データの大きさ                 */
/********************************************/
char **pbm_read(FILE *fp,int *x, int *y) {
	char **data;
	int i, j;
	int res;
	/* この関数は未完成であり、問題2の完成対象である */
	if(fgetc(fp) != 'P' || fgetc(fp) != '1'){
		return NULL;
	}
	fscanf(fp, "%d %d", x, y);
	data = pbm_alloc(*x, *y);
	for(i = 0; i < *y; i++){
		for(j = 0; j < *x; j++){
			
			res = fscanf(fp, " %c", &data[i][j]);
			if(res != 1){
				pbm_free(data, *x, *y);
				return NULL;
			}
		}
	}
	return data;
}


char **pbm_erode(char **pbm, int x, int y){
  char **data;
  int i, j, k, l;
  data = pbm_alloc(x, y);
  for(i = 0; i < y; i++){
    for(j = 0; j < x; j++){
      if(pbm[i][j] == BLACK){
        if(i == 0 || j == 0 || i == y - 1 || j == x - 1){
          if(i == 0 && j == 0){
            if(pbm[i][j + 1] == BLACK && pbm[i + 1][j] == BLACK){
              data[i][j] = BLACK;
            }else{
              data[i][j] = WHITE;
            }
          }else if(i == 0 && j == x - 1){
            if(pbm[i][j - 1] == BLACK && pbm[i + 1][j] == BLACK){
              data[i][j] = BLACK;
            }else{
              data[i][j] = WHITE;
            }
          }else if(i == y - 1 && j == 0){
            if(pbm[i][j + 1] == BLACK && pbm[i - 1][j] == BLACK){
              data[i][j] = BLACK;
            }else{
              data[i][j] = WHITE;
            }
          }else if(i == y - 1 && j == x - 1){
            if(pbm[i][j - 1] == BLACK && pbm[i - 1][j] == BLACK){
              data[i][j] = BLACK;
            }else{
              data[i][j] = WHITE;
            }
          }else if(i == 0){
            if(pbm[i][j - 1] == BLACK && pbm[i][j + 1] == BLACK && pbm[i + 1][j] == BLACK){
              data[i][j] = BLACK;
            }else{
              data[i][j] = WHITE;
            }
          }else if(i == y - 1){
            if(pbm[i][j - 1] == BLACK && pbm[i][j + 1] == BLACK && pbm[i - 1][j] == BLACK){
              data[i][j] = BLACK;
            }else{
              data[i][j] = WHITE;
            }
          }else if(j == 0){
            if(pbm[i - 1][j] == BLACK && pbm[i + 1][j] == BLACK && pbm[i][j + 1] == BLACK){
              data[i][j] = BLACK;
            }else{
              data[i][j] = WHITE;
            }
          }else if(j == x - 1){
            if(pbm[i - 1][j] == BLACK && pbm[i + 1][j] == BLACK && pbm[i][j - 1] == BLACK){
              data[i][j] = BLACK;
            }else{
              data[i][j] = WHITE;
            }
          }
        }else{
          if(pbm[i - 1][j] == BLACK &&  pbm[i][j - 1] == BLACK && pbm[i][j + 1] == BLACK && pbm[i + 1][j] == BLACK){
            data[i][j] = BLACK;
          }
          else{
            data[i][j] = WHITE;
          }
        }
      }else{
        data[i][j] = WHITE;
      }
      
    }
  }
  return data;
}

char **pbm_dilate(char **pbm, int x, int y){
  char **data;
  int i, j, k, l;
  data = pbm_alloc(x, y);
  for(i = 0; i < y; i++){
    for(j = 0; j < x; j++){

        if(i == 0 || j == 0 || i == y - 1 || j == x - 1){
          if(i == 0 && j == 0){
            if(pbm[i][j] == BLACK || pbm[i][j + 1] == BLACK || pbm[i + 1][j] == BLACK){
              data[i][j] = BLACK;
            }else{
              data[i][j] = WHITE;
            }
          }else if(i == 0 && j == x - 1){
            if(pbm[i][j] == BLACK || pbm[i][j - 1] == BLACK || pbm[i + 1][j] == BLACK){
              data[i][j] = BLACK;
            }else{
              data[i][j] = WHITE;
            }
          }else if(i == y - 1 && j == 0){
            if(pbm[i][j] == BLACK || pbm[i][j + 1] == BLACK || pbm[i - 1][j] == BLACK){
              data[i][j] = BLACK;
            }else{
              data[i][j] = WHITE;
            }
          }else if(i == y - 1 && j == x - 1){
            if(pbm[i][j] == BLACK || pbm[i][j - 1] == BLACK || pbm[i - 1][j] == BLACK){
              data[i][j] = BLACK;
            }else{
              data[i][j] = WHITE;
            }
          }else if(i == 0){
            if(pbm[i][j] == BLACK || pbm[i][j - 1] == BLACK || pbm[i][j + 1] == BLACK || pbm[i + 1][j] == BLACK){
              data[i][j] = BLACK;
            }else{
              data[i][j] = WHITE;
            }
          }else if(i == y - 1){
            if(pbm[i][j] == BLACK || pbm[i][j - 1] == BLACK || pbm[i][j + 1] == BLACK || pbm[i - 1][j] == BLACK){
              data[i][j] = BLACK;
            }else{
              data[i][j] = WHITE;
            }
          }else if(j == 0){
            if(pbm[i][j] == BLACK || pbm[i - 1][j] == BLACK || pbm[i + 1][j] == BLACK || pbm[i][j + 1] == BLACK){
              data[i][j] = BLACK;
            }else{
              data[i][j] = WHITE;
            }
          }else if(j == x - 1){
            if(pbm[i][j] == BLACK || pbm[i - 1][j] == BLACK || pbm[i + 1][j] == BLACK || pbm[i][j - 1] == BLACK){
              data[i][j] = BLACK;
            }else{
              data[i][j] = WHITE;
            }
          }
        }else{
          if(pbm[i][j] == BLACK || pbm[i - 1][j] == BLACK || pbm[i][j - 1] == BLACK || pbm[i][j + 1] == BLACK || pbm[i + 1][j] == BLACK){
            data[i][j] = BLACK;
          }else{
            data[i][j] = WHITE;
          }
        }
      
    }
  }
  return data;
}