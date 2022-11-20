#include <stdio.h>
#include <stdlib.h>
 
typedef struct {
  int x;        /* アリの位置（横） */
  int y;        /* アリの位置（縦） */
  char dr;      /* 'R':右向き  'D':下向き */
  int in;       /* 1:アリは盤上にいる 0:既に盤外に出ている */
}AntPos;
 
int main(int argc, char *argv[])
{
  int w, h, n;  /* 幅、高さ、初期状態でのアリの数 */
  int t=0;      /* 時間ステップのカウンタ */
  int i, j, num;
  AntPos *ant;
  FILE *ifile;
 
  if (argc < 2) {
    printf( "error: input file name is required!\n");
    exit(1);
  }
  /* ファイルオープン */
  ifile = fopen(argv[1], "r");

  /* ファイルの1行目から盤の幅w、高さh、アリの数nを読み込む */
  fscanf(ifile, "%d %d %d", w, h, n);

  /* アリの情報を収めておく構造体配列を動的に確保 */
  ant = malloc(sizeof(AntPos) * n);
 
  /* ファイルから各アリの位置と向きを読み込む。なお、文字型を読む時は
     " %c"のように%c手前にスペースを入れると、R/D手前のスペースを読み飛ばせる。
     読み込めたら、確認のため読んだ情報を一度出力しておこう */
  for(i = 0; i < n; i++){
    fscanf(ifile, "%d %d %c", ant[i].x, ant[i].y, ant[i].dr);
    printf("")
  }
 
  /* 1ステップごとのループ。盤上にいるアリの数が0になったら終了 */
    /* 時間の更新、アリの座標の更新、アリが盤の外に出たかどうかのチェックと表示、
       2匹のアリが同じマスにいるかどうかのチェックと（必要なら）向きの更新 */

  for (t = 0; num > 0; t++)
    while (num > 0)
    {
      t++;
      for (i = 0; i < n; i++)
      {
        if (ant[i].in == 1)
        {
          if (ant[i].dr == 'R')
          {
            ant[i].x++;
          }
          if (ant[i].dr == 'D')
          {
            ant[i].y++;
          }
          if (ant[i].x > w || ant[i].y > h)
          {
            ant[i].in = 0;
            num--;
            printf("Step %d: Ant No.%d has gone out to (%d,%d).\n", t, i, ant[i].x, ant[i].y);
          }
          for (j = 0; j < n; j++)
          {
            if (i != j && ant[i].x == ant[j].x && ant[i].y == ant[j].y)
            {
              printf("aaaaaaaa\n");
              /*
              ant[i].dr = 'D';
              ant[j].dr = 'R';
              */
            }
          }
        }
      }
    }
 
  return 0;
}