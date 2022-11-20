#include <stdio.h>
int main(void){
    // Your code here!
    int data[5];     /* 配列の宣言 */
  int tmp;
  int *p,*q,*min_ptr;

  printf("Please input %d numbers\n", 5);
  scanf("%d", data);
 for(int i = 0; i < 5;i++){
  printf("%d", data[i]);  
 } 
  printf("\n");
}
