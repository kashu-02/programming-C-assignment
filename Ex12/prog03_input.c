#include <stdio.h>

#include "prog03.h"


int input_planet(Planet *data){
  int i, input_result;
  FILE *fp;

  if((fp = fopen("planet.txt", "r")) == NULL) return -1;
  for (i = 0;; i++){
    input_result = fscanf(fp, "%s %lf %lf %lf", data[i].name, &data[i].radius, &data[i].density, &data[i].orbital_radius);
    if (input_result != 4 && input_result != EOF){
      fclose(fp);
      return -1;
    }
    if(input_result == EOF){
      fclose(fp);
      return 0;
    }
  }
}