#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 300000
typedef struct{
	int data[N]; /* N個の要素を持つ配列 */
	int max;     /* データの最大値 */
	int min;     /* データの最小値 */
	double ave;  /* データの平均値 */
}My_Array;

void FindMember1(My_Array*);
My_Array FindMember2(My_Array);

/* 以下の構造体変数の宣言はmain()関数の中に書くこと */
int main(){
  My_Array A;
  int i;
  long time1[2], time2[2];
  srand((unsigned int)time(NULL));
  for(i = 0; i < N; i++){
    A.data[i] = rand() % 1000;
  }
  time1[0] = clock();
  FindMember1(&A);
  time1[1] = clock();
  printf("FindMember1\n");
  printf("Maximum value: %d\n", A.max);
  printf("Minimum value: %d\n", A.min);
  printf("Average value: %f\n", A.ave);
  printf("\n");
  time2[0] = clock();
  A = FindMember2(A);
  time2[1] = clock();
  printf("FindMember2\n");
  printf("Maximum value: %d\n", A.max);
  printf("Minimum value: %d\n", A.min);
  printf("Average value: %f\n", A.ave);

  printf("--- time ---\n");
  printf("FindMember1: %lf sec\n", (time1[1] - time1[0])/(double) CLOCKS_PER_SEC);
  printf("FindMember2: %lf sec\n", (time2[1] - time2[0])/(double) CLOCKS_PER_SEC);
}

void FindMember1(My_Array *array){
  int i;
  array->max = 0;
  array->min = 1000;
  array->ave = 0.0;

  for (i = 0; i < N; i++)
  {
    if(array->data[i] > array->max){
      array->max = array->data[i];
    }
    if(array->data[i] < array->min){
      array->min = array->data[i];
    }
    array->ave += array->data[i];
  }
  array->ave /= N;
}

My_Array FindMember2(My_Array array){
  int i;
  array.max = 0;
  array.min = 1000;
  array.ave = 0.0;

  for (i = 0; i < N; i++)
  {
    if(array.data[i] > array.max){
      array.max = array.data[i];
    }
    if(array.data[i] < array.min){
      array.min = array.data[i];
    }
    array.ave += array.data[i];
  }
  array.ave /= N;

  return array;
}