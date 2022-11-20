#include <stdio.h>

char scoreToGrade(int);
int gradeToPoint(char);

int main(){
  int status;
  int grade, unit, gp;
  int total_unit = 0, total_gp = 0;
  char eval;

  while(1){
    printf("評点と単位数を入力してください (Ctrl+Dで終了): ");
    status = scanf("%d %d", &grade, &unit);
    if(status == -1){
      printf("\nGrade Point Average (GPA): %f,  単位数: %d\n", (double)total_gp / total_unit, total_unit);
      break;
    }

    eval = scoreToGrade(grade);
    gp = gradeToPoint(eval);
    total_unit += unit;
    total_gp += gp * unit;

    printf("%d 点の評価は %c で, Grade Point (GP) は %d です． (%d 単位)\n\n", grade, eval, gp, unit);
  }
  return 0;
}

char scoreToGrade(int score){
  if(score >= 0 && score <= 34){
    return 'F';
  }else if(score >= 35 && score <= 49){
    return 'D';
  }else if(score >= 50 && score <= 64){
    return 'C';
  }else if(score >= 65 && score <= 79){
    return 'B';
  }else if(score >= 80 && score <= 100){
    return 'A';
  };
}

int gradeToPoint(char grade){
  if(grade == 'F'){
    return 0;
  }else if(grade == 'D'){
    return 0;
  }else if(grade == 'C'){
    return 2;
  }else if(grade == 'B'){
    return 3;
  }else if(grade == 'A'){
    return 4;
  };
}
