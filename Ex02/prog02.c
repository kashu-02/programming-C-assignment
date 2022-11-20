#include <stdio.h>
#define ROW 3
#define COL 4
 
int main()
{
  int array[ROW][COL] = {
    { 2,  3, 12,  3},
    { 4, 10,  5,  6},
    { 8,  9,  0,  7},
  };
  int n;
  /* 必要に応じて変数宣言を追加 */
  int i, j;
  int count = 0;
 
  printf("数値を入力してください: ");
  scanf("%d", &n);
  
  for(i = 0; i < ROW; i++){
    for(j = 0; j < COL; j++){
      if(array[i][j] == n){
        printf("array[%d][%d] が %d です\n", i, j, n);
        count++;
      }
    }
  }

  if(count == 0){
    printf("2次元配列 array の要素に %d はありません\n", n);
  }else{
    printf("2次元配列 array の要素に %d は %d 個ありました\n", n, count);
  }

  return 0;
}
