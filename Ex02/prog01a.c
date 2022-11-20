#include <stdio.h>

void SeqAvgExt (double);

double avg;
int cnt;

int main() {
  double data;
  while (1){
    printf("データを入力して下さい: ");
    if (scanf("%lf", &data) == EOF) break;
    SeqAvgExt(data);
    printf("データの個数 = %d, ここまでの平均 = %f\n", cnt, avg);
  }

  printf("\n最終的な平均値は%fです。\n", avg);
  return 0;
}

void SeqAvgExt (double x){
  avg = (avg * cnt + x) / (cnt + 1);
  cnt++;
}