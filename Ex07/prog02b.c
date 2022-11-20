#include <stdio.h>
#include "prog01.h"

#define YEAR 2022
#define MONTH 10
#define DAY 1

Record input(void);
void output(Record);
int getAge(Record);

int main(){
  Record data[2];

  printf("--------データ入力--------\n");
  printf("1人目の データを入力して下さい\n");
  data[0] = input();
  printf("\n");
  printf("2人目の データを入力して下さい\n");
  data[1] = input();

  printf("--------データ出力--------\n");
  printf("年齢基準日: %d/%d/%d\n", YEAR, MONTH, DAY);
  printf("1人目のデータ:\n");
  output(data[0]);
  printf("年齢: %d\n", getAge(data[0]));
  printf("\n");
  printf("2人目のデータ:\n");
  output(data[1]);
  printf("年齢: %d\n", getAge(data[1]));
}

Record input(void){
  Record data;

  printf("データを入力して下さい\n");
  printf("苗字 -> ");
  scanf("%s", data.familyname);
  printf("名前 -> ");
  scanf("%s", data.firstname);
  printf("生まれた年(西暦) -> ");
  scanf("%d", &data.birthday[0]);
  printf("生まれた月 -> ");
  scanf("%d", &data.birthday[1]);
  printf("生まれた日 -> ");
  scanf("%d", &data.birthday[2]);

  return data;
}

void output(Record data){
  printf("苗字: %s\n名前: %s\n生年月日: %d/%d/%d\n", data.familyname, data.firstname, data.birthday[0], data.birthday[1], data.birthday[2]);
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

