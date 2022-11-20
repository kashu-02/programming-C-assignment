#include <stdio.h>

double avesub_arr(double *);   /* プロトタイプ宣言 */

int main()
{
  double a[3], ave;

  printf("3つ値を入力してください:\n");
  scanf("%lf%lf%lf", &a[0], &a[1], &a[2]);

  ave = avesub_arr( a );   /* 関数の呼び出し */

  printf("平均:  %.3f\n", ave);
  printf("平均差し引き後のデータ:  %+.3f  %+.3f  %+.3f\n", a[0], a[1], a[2]);
  return 0;
}

/* 平均を計算して各データから引き算する関数。戻り値はその平均値。 */
double avesub_arr(double *a)
{
  /* ここを適宜作成 */
  double average = (a[0] + a[1] + a[2]) / 3;
  a[0] -= average;
  a[1] -= average;
  a[2] -= average;
  return average;
}