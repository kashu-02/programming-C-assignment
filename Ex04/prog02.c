#include <stdio.h>
 
int main(){
  double a = 7.0, b = 3.5;
  double *p, *q;
  
  /*
   * ここでポインタ変数p, qに適切な代入を行う
   * さらに以下の4行を変数 a, b を使わない形に書き換える
   */

  p = &a;
  q = &b;

 
  printf("Value of a: %.1f, Address of a: %p\n", *p, p);
  printf("Value of b: %.1f, Address of b: %p\n", *q, q);
  printf("Product: %.1f\n", *p * *q);
  printf("Quotient: %.1f\n", *p / *q);
  return 0;
}