#include <stdio.h>

typedef struct{
	int id;           /* ID */
	char name[10];    /* 名前 */
	int grade;        /* 学年 */
	char subject[10]; /* 科目名 */
	char record;      /* 成績 */
} StudentInfo;

void PrintInfo1(StudentInfo);
void PrintInfo2(StudentInfo *);

int main(){
  StudentInfo student1 = {
      1300071,
      "Kasuya",
      1,
      "Prog C",
      'A',
  };

  StudentInfo student2 = {
    1300072,
    "Taro",
    2,
    "Prog C",
    'A',
  };


  printf("構造体の値渡し\n");
  PrintInfo1(student1);
  PrintInfo1(student2);
  printf("構造体のアドレス値渡し\n");
  PrintInfo2(&student1);
  PrintInfo2(&student2);

  return 0;
}

void PrintInfo1(StudentInfo student){
  printf("%d\t%s\t%d\t%s\t%c\n", student.id, student.name, student.grade, student.subject, student.record);
}

void PrintInfo2(StudentInfo *student){
  printf("%d\t%s\t%d\t%s\t%c\n", (*student).id, (*student).name, (*student).grade, (*student).subject, (*student).record);
}


