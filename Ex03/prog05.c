#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char** argv){
 
	FILE *fpin1, *fpin2;
	int data1, data2;
	int file1_end = 0, file2_end = 0;

	/* 入力ファイルその１を開く */
	if ((fpin1 = fopen(argv[1], "r")) == NULL){
		printf("Failed to open: %s\n", argv[1]);
		exit(1);
	}
	
	/* 入力ファイルその２を開く */
	if ((fpin2 = fopen(argv[2], "r")) == NULL){
		printf("Failed to open: %s\n", argv[2]);
		fclose(fpin1);
		exit(2);
	}
	
	/*
	 * 数値の読み込みと処理，および結果を出力する
	 */
	if(fscanf(fpin1, "%d", &data1) == EOF){
		file1_end = 1;
	}
	if(fscanf(fpin2, "%d", &data2) == EOF){
		file2_end = 1;
	}
	
	while(1){
		if(file1_end == 1 && file2_end == 0){
			printf("%d\n", data2);
			if(fscanf(fpin2, "%d", &data2) == EOF){
					file2_end = 1;
			}
		}else if(file1_end == 0 && file2_end == 1){
			printf("%d\n", data1);
			if(fscanf(fpin1, "%d", &data1) == EOF){
					file1_end = 1;
			}
		}else if(file1_end == 0 && file2_end == 0){
			if(data1 >= data2){
				printf("%d\n", data2);
				if(fscanf(fpin2, "%d", &data2) == EOF){
					file2_end = 1;
				}
			}else if(data2 > data1){
				printf("%d\n", data1);
				if(fscanf(fpin1, "%d", &data1) == EOF){
					file1_end = 1;
				}
			}
		}else if(file1_end == 1 && file2_end == 1) break;
	}

		/* 開いた入力ファイルをそれぞれ忘れずに閉じて終了する */
	fclose(fpin1);
	fclose(fpin2);
	return 0;
}