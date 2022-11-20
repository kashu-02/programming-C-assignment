#include <stdio.h>


int calculate(int, int);
int fibonacci(int);

int main(){
  int a0 = 1, a1 = 1;
  int n;

  printf("n = ");
  scanf("%d", &n);
}

int fibonacci(int n){
  static int count = 0;

  printf("called %d times: n=%d\n", count, n);
  if(n == 0 || n == 1) return 1;
  return fibonacci(n - 1) + fibonacci(n - 2)
}

int calculate(int an_1, int an_2){



}