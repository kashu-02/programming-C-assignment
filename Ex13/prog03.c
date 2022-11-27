#include <stdio.h>
#include <stdlib.h>

#define BLACK '1'
#define WHITE '0'

char **pbm_alloc(int, int);
void   pbm_free(char **,int, int);
char **pbm_read(int *, int *);
void   pbm_write(char **, int, int);
char **pbm_erode(char **pbm, int x, int y);  /* エロージョンを行う関数 */
char **pbm_dilate(char **pbm, int x, int y); /* ダイレーションを行う関数 */



int main(){
  char **pbm1, **pbm2;
  int ix,iy;
 
  pbm1 = pbm_read(&ix,&iy);
  if(pbm1==NULL){
    fprintf(stderr,"Invalid image format.");
    exit(1);
  }
 
  #ifdef ERODE
  pbm2=pbm_erode(pbm1,ix,iy);
  pbm_free(pbm1,ix,iy);
  #elif DILATE
  pbm2=pbm_dilate(pbm1,ix,iy);
  pbm_free(pbm1,ix,iy);
  #else
  pbm2=pbm1;
  #endif
 
  /* 画像を書きだす */
  pbm_write(pbm2,ix,iy);
  /* 画像領域の解放 */
  pbm_free(pbm2,ix,iy);
  return 0;
}


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
char **pbm_read(int *x, int *y) {
	char **data;
	int i, j;
	int res;
	/* この関数は未完成であり、問題2の完成対象である */
	if(getchar() != 'P' || getchar() != '1'){
		return NULL;
	}
	scanf("%d %d", x, y);
	data = pbm_alloc(*x, *y);
	for(i = 0; i < *y; i++){
		for(j = 0; j < *x; j++){
			
			res = scanf(" %c", &data[i][j]);
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