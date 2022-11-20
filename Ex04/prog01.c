#include <stdio.h>
 
int main(){
 
  int num = 567;
  int *p;
  p = &num;
 
  printf("(a) %d\n", num);
  printf("(b) %p\n", &num);
  printf("(c) %d\n", *(&num));
  printf("(d) %p\n", p);
  printf("(e) %p\n", &p);
  printf("(f) %d\n", *p);
  printf("(g) %p\n", &(*p));
 
  return 0;
}
