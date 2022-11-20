#include <stdio.h>
#define N 5
#define EMPTY -1
#define FULL  -2
 
int queueIO(int);
 
int main()
{
  int n, r;
 
  printf("キューを実現するプログラム\n");
  printf("  正の整数値：入力値をキューに格納する(Enqueue)\n");
  printf("  負の整数値：キューからデータを取り出す(Dequeue)\n");
  printf("  0：終了\n");
  while (1) {
    printf("整数値を入力 (正：格納 (Enqueue)，負：取出 (Dequeue)，0：終了): ");
    scanf("%d", &n);
    if (n == 0) break; /* 終了 */
    r = queueIO(n); /* 格納または取出 */
    if (r > 0) printf("取出データ: %d\n", r); /* 取得データの表示 */
    else if (r == EMPTY) printf("エラー（キューが空です）\n"); 
    else if (r == FULL ) printf("エラー（キューが満杯です）\n"); 
    queueIO(0); /* 表示 戻り値(0)は使用しない */
  }
  return 0;
}
 
/* 
[引数]
正の整数: 格納，負の整数: 取出，0: 表示
[戻り値]
格納の場合) キューが満杯: マクロ定数 FULL，それ以外: 0
取出の場合) キューが空: マクロ定数 EMPTY，それ以外: 取り出した値
表示の場合) 0
*/
int queueIO(int x)
{
  static int queue[N]; /* データを格納する配列 */
  static int head = 0, tail = 0, size = 0; /* 先頭，末尾，データ数 */
  int i, ret;

  
  if(x > 0){
    if(size == N) return FULL;
    size++;
    queue[tail] = x;
    tail = (tail + 1) % N;
    return 0;
  }else if(x < 0){
    if(size == 0) return EMPTY;
    ret = head;
    head = (head + 1) % N;
    size--;
    return queue[ret];
  } else if(x == 0){
    printf("head = %d, tail = %d, size = %d [", head, tail, size);
    if(size == 0){
      
    }else if (head < tail){
      for (i = head; i < tail; i++){
        printf("%d ", queue[i]);
      }
    }else if(tail <= head){
      for(i = head; i < head + (size - tail); i++){
        printf("%d ", queue[i]);
      }
      for (i = 0; i < tail; i++){
        printf("%d ", queue[i]);
      }
    }
    printf("]\n");
    return 0;
  }
  return 0;
}