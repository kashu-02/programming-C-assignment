#include <stdio.h>

double SeqAvgStatic(double);

double avg;
int cnt;

int main() {
  double data;
  double avg;
  int cnt = 0;
  while (1){
    printf("データを入力して下さい: ");
    if (scanf("%lf", &data) == EOF) break;
    avg = SeqAvgStatic(data);
    cnt++;
    printf("データの個数 = %d, ここまでの平均 = %f\n", cnt, avg);
  }

  printf("\n最終的な平均値は%fです。\n", avg);
  return 0;
}

double SeqAvgStatic(double x){
  static double avg = 0.0;
  static int cnt = 0;

  avg = (avg * cnt + x) / (cnt + 1);
  cnt++;

  return avg;
}