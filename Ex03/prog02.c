#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main(){
  int data, max = 0, min = INT_MAX;
  FILE *fpin, *fpout;


  /*
   * Open input2.txt
   */
  if((fpin = fopen("input2.txt", "r")) == NULL){
      printf("Failed to open: input2.txt\n");
      exit(1);
  }

  /*
   * Open result2.txt
   */
  if((fpout = fopen("result2.txt", "w")) == NULL){
      printf("Failed to open: result2.txt\n");
      fclose(fpin);
      exit(2);
  }


  while(fscanf(fpin, "%d", &data) != EOF){
    if(data > max) max = data;
    if(data < min) min = data;
  }


  fprintf(fpout, "max = %d, min = %d", max, min);

  fclose(fpout);
  fclose(fpin);

  return 0;
}