#include <stdio.h>
#include "prog04_1.h"     /* (1) */
/* 必要に応じて追加、修正してもよい */

int main() {     /* (2) */
  /* 必要に応じてコードを追加 */
  Triangle triangle1, triangle2;
  int time = 1;
  /* １つ目の三角形の３頂点の座標を入力する */
  triangle1 = InputTriangle(time );     /* 引数・戻り値は適宜設計せよ (3) */
  /* １つ目の三角形の面積を求める */
  CalcArea(&triangle1);     /* 引数・戻り値を入れる変数等は適宜設計せよ (4) */
  
  /* CalcAreaの結果をもとに、先へ進むか，再入力を求める */
  
  /* ２つ目の三角形の３頂点の座標を入力する */
  InputTriangle( );   /* 引数・戻り値は適宜設計せよ (3) */
  /* ２つ目の三角形の面積を求める */
  CalcArea( );   /* 引数・戻り値を入れる変数等は適宜設計せよ (4) */

  /* CalcAreaの結果をもとに、先へ進むか，再入力を求める */
  

  printf( /* CalcAreaで求めた三角形の面積を２つ表示 */ );

  /* 面積の大きい方を判定して、表示 */

  /* １つ目の三角形の重心を求める */
  CalcCentroid( );   /* 引数・戻り値等は適宜設計せよ (5) */
  /* ２つ目の三角形の重心を求める */
  CalcCentroid( );   /* 引数・戻り値等は適宜設計せよ (5) */
  
  printf( /* CalcCentroidで求めた三角形の重心２つを表示 */ );

  return 0;
}