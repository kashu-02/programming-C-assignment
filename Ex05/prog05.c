#include <stdio.h>

#define N 5

int main()
{
  int data[N];     /* 配列の宣言 */
  int tmp;
  int *p,*q,*min_ptr;

  printf("Please input %d numbers\n", N);
  p = data;        /* pに配列の先頭アドレスを代入 */
  while(p <= &data[N - 1]) scanf("%d", p++);

  for (p = data; p < data + N; p++) {
    min_ptr = p;
    for (q = p + 1; q < data + N; q++) {
      if (*q < *min_ptr) {
        min_ptr = q;
      }
    }
    tmp = *p;
    *p = *min_ptr;
    *min_ptr = tmp;
  }



  printf("Sorted data\n");
  p = data;
  while(p <= &data[N - 1]) printf("%d ", *(p++));
  printf("\n");
  return 0;
}