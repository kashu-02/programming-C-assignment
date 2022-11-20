#include <stdio.h>
#include <string.h>


/*
文字列のn文字目の後ろに、標準入力から入力した単語を挿入するプログラムを作成せよ。プログラムの動作は以下のようにすること。

標準入力から、挿入する場所（n）、半角空白 1 文字、単語を順に入力すると、 既に入力されている文字列の n 番目から、入力した単語を { } で囲んで挿入する。
文字列のためのバッファは 256要素 とする。文字列には末尾にヌル文字が付加されるため、 保持できる文字数は最大255文字である。ただし、挿入された { } も文字数としてカウントする。
はじめにバッファに入っている文字列を [Wakamatsu]としておく。（※{Wakamatsu}でないことに注意してください。）
入力・挿入は繰り返すものとし、EOF (Ctrl-D) を読み込んだ際に終了する。
また以下のようなエラーがあった場合には、エラーを表示して次の入力を受け付けること。

挿入する場所（n）に保持している文字数よりも大きい値が与えられた場合
挿入時に全体の文字数が 255文字 を越える場合
*/


int main(){
  char buf[256] = "[Wakamatsu]";
  char buf_copy[256];
  int word_count = 11;
  int i, n;
  char word[245];


  while(1){
    printf("Current string: %s\n", buf);
    printf("input-> ");
    if(scanf("%d %s", &n, word) == EOF) break;
    if(word_count < n ){
      printf("Error in position\n");
      continue;
    }
    if(word_count + strlen(word) > 253){
      printf("Error in length\n");
      continue;
    }

    strcpy(buf_copy, buf);

    buf_copy[n] = '{';
    strcpy(buf_copy + n + 1, word);
    buf_copy[n + strlen(word) + 1] = '}';
    strcpy(buf_copy + n + strlen(word) + 2, buf + n);

    strcpy(buf, buf_copy);
    word_count += strlen(word) + 2;


  }

  printf("\n");
  return 0;
}
