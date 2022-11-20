#include <stdio.h>
#include <stdlib.h>
 
int main(){
	char in_filename1[] = "output3.txt";
  char in_filename2[] = "output3-ans.txt";
	FILE *fpin1, *fpin2;
	
	int c1, c2;         /* ファイルからの1文字 */
	int n;         /* 読み込んだ文字数 */
	int i = 1;
	
	/* 入力ファイル1を開く */
	if((fpin1 = fopen(in_filename1, "r")) == NULL){
		printf("Failed to open: %s\n", in_filename1);
		exit(1);
	}
	
	/* 入力ファイル2を開く */
	if((fpin2 = fopen(in_filename2, "r")) == NULL){
		printf("Failed to open: %s\n", in_filename2);
		exit(1);
	}
	
	/* 比較 */
  while(1){
		c1 = fgetc(fpin1);
		c2 = fgetc(fpin2);
    if( c1 != EOF || c2 != EOF){
			if(c1 != c2){
				printf("Two files are different at %d byte.\n", i);
				break;
			}
		}	
		if(c1 == EOF && c2 == EOF){
			printf("Two files are identical.\n");
			break;
		}
		i++;
	}
		/* 開いた入出力ファイルをそれぞれ忘れずに閉じる */
	fclose(fpin1);
	fclose(fpin2);

	return 0;
}