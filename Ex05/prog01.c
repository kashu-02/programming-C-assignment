#include <stdio.h>
int main()
{
  int i;
  int array[] = {11,22,33,44};

  long l_array[] = {128,256,512,1024};
  double d_array[] = {1e+4, 2e+3, 3e+2, 4e+1};
  char c_array[] = {'a','b','c','d'};
  char c_2d_array[][7] = {"ab","c","defg","hij"};
  char *str_array[] = {"ABC","DE","F","GHI"};

  for(i = 0 ; i < 4 ; i++)
    printf( "%d %p %d\n",i,&array[i],array[i]);
  printf("\n%p\n\n",array);

  for(i = 0 ; i < 4 ; i++)
    printf( "%d %p %f\n",i,&d_array[i],d_array[i]);
  printf("\n%p\n\n",d_array);

  for(i = 0 ; i < 4 ; i++)
    printf( "%d %p %c\n",i,&c_array[i],c_array[i]);
  printf("\n%p\n\n",c_array);

  for(i = 0 ; i < 4 ; i++)
    printf( "%d %p %s\n",i,&c_2d_array[i],c_2d_array[i]);
  printf("\n%p\n\n",c_2d_array);

  for(i = 0 ; i < 4 ; i++)
    printf( "%d %p %s\n",i,&str_array[i],str_array[i]);
  printf("\n%p\n\n",str_array);

  printf("Size of each type\n");
  printf(" int: %ld,  long: %ld,  double: %ld,  char: %ld\n", sizeof(int), sizeof(long), sizeof(double), sizeof(char));
  printf(" int*: %ld, long*: %ld, double*: %ld, char*: %ld\n", sizeof(int *), sizeof(long *), sizeof(double *), sizeof(char *));

  return 0;
}
