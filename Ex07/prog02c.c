#include <stdio.h>
#include "prog01.h"

#define YEAR 2022
#define MONTH 10
#define DAY 1

#define N 20

Record input(void);
void output(Record);
int getAge(Record);

int main(){
  Record data[N];
  int i, n;
  for (i = 0; i < N; i++) {
    data[i] = input();
    if(data[i].birthday[0] == -1){
      n = i;
      break;
    };
  }

  for(i = 0; i < n; i++){
    output(data[i]);
  }
}

Record input(void){
  Record data;
  if(scanf("%s %s %d %d %d", data.familyname, data.firstname, &data.birthday[0], &data.birthday[1], &data.birthday[2]) == EOF){
    data.birthday[0] = -1;
  }
  return data;
}

void output(Record data){
  printf("氏名: %s %s,\t生年月日: %d/%d/%d,\t年齢:%d\n", data.familyname, data.firstname, data.birthday[0], data.birthday[1], data.birthday[2], getAge(data));
}

int getAge(Record data){
  int age;
  age = YEAR - data.birthday[0];
  if(data.birthday[1] > MONTH){
    age--;
  }else if(data.birthday[1] == MONTH){
    if(data.birthday[2] > DAY){
      age--;
    }
  }
  return age;
}

