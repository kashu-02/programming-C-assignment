#include <stdio.h>

int fibonacci(int);

int main(){
  int a0 = 1, a1 = 1;
  int n, result;

  printf("n = ");
  scanf("%d", &n);

  result = fibonacci(n);

  printf("fibonacci(%d) = %d\n", n, result);
}

int fibonacci(int n){
  static int count = 1;

  printf("called %d times: n=%d\n", count++, n);
  if(n == 0 || n == 1) return 1;
  return fibonacci(n - 1) + fibonacci(n - 2);
}