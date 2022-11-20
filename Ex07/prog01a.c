#include <stdio.h>

/* 個人レコード */
struct record{
  char familyname[20]; /* 苗字 */
  char firstname[20];  /* 名前 */
  int birthday[3];     /* 誕生日（要素0: 西暦, 要素1: 月, 要素2:日） */
};

int main(){
  struct record data; /* この1行は main関数に書いて外部変数にはしないこと */

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

  printf("\n");
  printf("苗字: %s\n名前: %s\n生年月日: %d/%d/%d\n", data.familyname, data.firstname, data.birthday[0], data.birthday[1], data.birthday[2]);
}