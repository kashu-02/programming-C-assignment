#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define N 4 /* ??? にはバッファ配列に問題条件に応じた適切な数値を指定する */
 
int main(){
 
	char code_file[] = "country-code.txt"; /* ??? には国名コードファイルのパスを指定する */
	// ↑相対パスで指定した。
  FILE *fp;
	
	char typein[N]; /* 入力コード用文字列バッファ */
	char pickup[N]; /* 国名コード用文字列バッファ */
	
	int status; /* fscanfの戻り値を格納する変数 */
	
	/* 無限ループ */
	while(1){
		printf("Input a code: ");
		if(scanf("%s", typein) == EOF) /* ※1 補足2を参照 */
			break;
			
		/*
		 * ファイルの先頭からコードの探索を行うために，
		 * 新たにコードが入力されるごとに
		 * 国名コードファイルのオープンとクローズを繰り返す
		 */
		if((fp = fopen(code_file, "r")) == NULL){
			printf("Failed to open: %s\n", code_file);
			exit(2);
		}
		
		/* 
		 * ここに，国名コードファイルのコードを1つずつ読み込みながら，
		 * 入力されたコードと一致するかをチェックする処理を追加せよ
		 */

    while(1){
      status = fscanf(fp, "%s", pickup);
      if(status == EOF){
        printf("The code \"%s\" is not found.\n", typein);
        break;
      };
      if(strcmp(typein, pickup) == 0){
        printf("The code \"%s\" is found.\n", typein);
        break;
      }
    }




		
		fclose(fp);
	}
	
	printf("\n");
	return 0;
}