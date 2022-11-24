#include <stdio.h>
#include "prog04_1.h"

Triangle InputTriangle(int time){
  Triangle triangle;
  int i;
  if(time == 1){
    printf("Input %dst triangle: \n", time);
  }else if(time == 2){
    printf("Input %dnd triangle: \n", time);
  }
  
  for(i = 0; i < 3; i++){
    printf("Vertex %d: ", i + 1);
    scanf("%lf %lf", &triangle.vertex[i].x, &triangle.vertex[i].y);
  }
  return triangle;




}