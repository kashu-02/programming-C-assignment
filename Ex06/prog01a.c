#include <stdio.h>

double avesub_ptr(double *, double *, double *);   /* プロトタイプ宣言 */

int main()
{
  double a, b, c, ave;

  printf("3つ値を入力してください:\n");
  scanf("%lf%lf%lf", &a, &b, &c);

  ave = avesub_ptr(&a, &b, &c);   /* 関数の呼び出し */

  printf("平均:  %.3f\n", ave);
  printf("平均差し引き後のデータ:  %+.3f  %+.3f  %+.3f\n", a, b, c);
  return 0;
}

/* 平均を計算して各データから引き算する関数。戻り値はその平均値。 */
double avesub_ptr(double *a, double *b, double *c)
{
  /* ここを適宜作成 */
  double average = (*a + *b + *c) / 3;
  *a -= average;
  *b -= average;
  *c -= average;
  return average;
}