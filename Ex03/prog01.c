#include <stdio.h>
#include <stdlib.h>

char toUpperCase(char);
char toLowerCase(char);
char reverseChar(char);
 
int main() {
    int i;
    int end;
    char c[500];
    FILE *fpin, *fpout;
 
    /*
     * 読み込み専用でファイル input1.txt を開く．
     * ファイルオープンに失敗した場合はエラーを表示して終了する．
     */
    if((fpin = fopen("input1.txt", "r")) == NULL){
        printf("Failed to open: input1.txt\n");
        exit(1);
    }
 
    /*
     * 書き込み専用でファイル output1-ans.txt を開く．
     * ファイルオープンに失敗した場合はエラーを表示して終了する．
     * その際，上で開いた入力ファイルを忘れずに閉じる．
     */
    if((fpout = fopen("output1-ans.txt", "w")) == NULL){
        printf("Failed to open: output1-ans.txt\n");
        fclose(fpin);
        exit(2);
    }
 
    /*
     * fpin を介して入力ファイルから，1文字ずつ読み込み，
     * そのまま fpout を介して出力ファイルに書き込む
     * 入力ファイルを最後まで読み込んだら，ループを抜ける．
     */
    for(i = 0; i < 500; i++){
      if(fscanf(fpin, "%c", &c[i]) == EOF){
        end = i;
        break;
      }
    }

    /*
     * 大文字→小文字
     */
    for(i = 0; i < end; i++){
      fprintf(fpout, "%c", toLowerCase(c[i]));
    }

    /*
     * 小文字→大文字
     */
     fprintf(fpout, "\n\n");
     for(i = 0; i < end; i++){
      fprintf(fpout, "%c", toUpperCase(c[i]));
    }

    /*
     * 大文字→小文字 && 小文字→大文字
     */
     fprintf(fpout, "\n\n");
     for(i = 0; i < end; i++){
      fprintf(fpout, "%c", reverseChar(c[i]));
    }
 
    /* 開いた入出力ファイルをそれぞれ忘れずに閉じる． */
    fclose(fpout);
    fclose(fpin);
 
    /* 正常終了を表す値0を返して終了する． */
    return 0;
 
}

char toUpperCase(char c){
  if(c >= 'a' && c <= 'z'){
    c -= 32;
  }
  return c;
}

char toLowerCase(char c){
  if(c >= 'A' && c <= 'Z'){
    c += 32;
  }
  return c;
}

char reverseChar(char c){
  if(c >= 'A' && c <= 'Z'){
    c += 32;
  }else if(c >= 'a' && c <= 'z'){
    c -= 32;
  }
  return c;
}