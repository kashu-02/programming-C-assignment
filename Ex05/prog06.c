#include <stdio.h>

int main(){
  int a[] = {1, 2, 4, 8, 16, 32};
  int b[2][3] = {{1, 3, 9}, {-1, -3, -9}};
  int *ptr;

  ptr = a;
  printf("(1) *ptr = %d    \t= %d\n", *ptr, a[0]); /* aを用いて配列風に */
  printf("(2) &a[2] = %p   \t= %p\n", &a[2], ptr + 2); /* ptrでポインタ演算 */
  printf("(3) *(ptr+3) = %d\t= %d\n", *(ptr+3), a[3]); /* aを用いて配列風に */
  ptr = &a[2];
  printf("(4) ptr[2] = %d  \t= %d\n", ptr[2], a[4]); /* aを用いて配列風に */
  printf("(5) *ptr-- = %d  \t= %d\n", *ptr--, a[2]); /* aを用いて配列風に */
  printf("(6) *ptr = %d    \t= %d\n", *ptr, a[1]); /* aを用いて配列風に */
  ptr = b[0];
  printf("(7) *++ptr = %d  \t= %d\n", *++ptr, b[0][1]); /* bを用いて配列風に */
  printf("(8) *(ptr+3) = %d\t= %d\n", *(ptr+3), b[1][1]); /* bを用いて配列風に */
  return 0;
}