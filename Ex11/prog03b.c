#include <stdio.h>
#include <stdlib.h>

int fibonacci_array(int, int *);

int main(){
  int a0 = 1, a1 = 1;
  int n, result;
  int i;
  int *fibo_array;

  printf("n = ");
  scanf("%d", &n);

  fibo_array = (int*) malloc(sizeof(int) * (n + 1));
  for (i = 0; i < n + 1; i++){
    *(fibo_array + i) = 0;
  }

  result = fibonacci_array(n, fibo_array);

  printf("fibonacci(%d) = %d\n", n, result);
}

int fibonacci_array(int n, int *a){
  static int count = 1;

  if(a[n] != 0) return a[n];
  printf("called %d times: n=%d\n", count++, n);
  if (n == 0 || n == 1)
    return 1;
  a[n] = fibonacci_array(n - 1, a) + fibonacci_array(n - 2, a);
  return a[n];
}