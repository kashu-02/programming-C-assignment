#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define MAXLEN 1024
 
int main(){
	int i;
	char c;
	FILE *fp;
	char buffer[MAXLEN];
	char query[MAXLEN];
	char buffer_prev[MAXLEN];
	int status;
	int arg1, arg2;
	int in_len, buf_len;
	
	/* ファイルのオープン */
	fp = fopen("myedit_in.txt", "r");
	if(fp == NULL){
		printf("Cannot open input file.\n");
		exit(1);
	}
	
	/* データの読み出し（最後に'\0'を忘れないこと） */
	buf_len = 0;
	while(1){
		c = fgetc(fp);
		if(c == EOF){
			buffer[buf_len++] = '\0';
			break;
		}
		else{
			buffer[buf_len++] = c;
		}
	}
	fclose(fp);
	
	/* コマンド入力のためのループ */
	while(1){
		status = scanf("%s", query);
		if(status != 1)
			break;
 
		/* 現在のテキストの長さを取得する */
		buf_len = strlen(buffer);
 
		/* それぞれのコマンドのチェック */
		if(strcmp("print", query) == 0){ /* printコマンド */
			/* printコマンドの処理を以下に書く */
      printf("%s\n", buffer);
			continue;
		}
		else if(strcmp("insert", query) == 0){ /* insertコマンド */
			if(scanf("%d %s", &arg1, query) == 2){
				/* insertコマンドの処理を以下に書く */
        if(buf_len < arg1){
          printf("ERROR\n");
          exit(1);
        }
        if(buf_len + strlen(query) > 1023){
          printf("ERROR\n");
          exit(1);
        }
        if(arg1 < 0){
          arg1 = buf_len;
        }

        strcpy(buffer_prev, buffer);

        strcpy(buffer + arg1 + strlen(query), buffer_prev + arg1);
        
				continue;
			}
		}
		/* 以下同様に，他のコマンドをプログラムを書く */
    else if(strcmp("cut", query) == 0){ /* cut */
			if(scanf("%d %s", &arg1, query) == 2){

        if(buf_len < arg1 || arg1 < 0){
          printf("ERROR\n");
          exit(1);
        }
        if(arg1 - arg2 < 0){
          printf("ERROR\n");
          exit(1);
        }

        strcpy(buffer_prev, buffer);
        strcpy(buffer + arg1, buffer_prev + arg2);
        strcpy(buffer + arg1 + 1, buffer_prev + arg1);
				continue;
			}
		}

    else if(strcmp("space", query) == 0){
			if(scanf("%d", &arg1) == 1){

        if(buf_len < arg1){
          printf("ERROR\n");
          exit(1);
        }
        if(buf_len + 1 > 1023){
          printf("ERROR\n");
          exit(1);
        }
        if(arg1 < 0){
          arg1 = buf_len;
        }

        strcpy(buffer_prev, buffer);

        strcpy(buffer + arg1, " ");
        strcpy(buffer + arg1 + 1, buffer_prev + arg1);
				continue;
			}
		}

    else if(strcmp("enter", query) == 0){
			if(scanf("%d", &arg1) == 1){

        if(buf_len < arg1){
          printf("ERROR\n");
          exit(1);
        }
        if(buf_len + 1 > 1023){
          printf("ERROR\n");
          exit(1);
        }
        if(arg1 < 0){
          arg1 = buf_len;
        }

        strcpy(buffer_prev, buffer);

        strcpy(buffer + arg1, "\n");
        strcpy(buffer + arg1 + 1, buffer_prev + arg1);
				continue;
			}
		}

    else if(strcmp("undo", query) == 0){
			printf("%d %s\n", arg1, query);
		}

    else if(strcmp("quit", query) == 0){
			fp = fopen("myedit_out.txt", "w");
      if(fp == NULL){
        printf("Cannot open output file.\n");
        exit(1);
      }
      for(i = 0; i < buf_len; i++){
        if(buffer[i] == '\0')
          break;
        fputc(buffer[i], fp);
      }
      fclose(fp);
      break;
		}
		
		/* 該当するコマンドが見付からないとき */
		printf("ERROR\n");
		exit(1);
	}
	
	return 0;
}