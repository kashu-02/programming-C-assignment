#include <stdio.h>

#define N 20

typedef struct{
	int id;           /* ID */
	char name[10];    /* 名前 */
	int grade;        /* 学年 */
	char subject[10]; /* 科目名 */
	char record;      /* 成績 */
} StudentInfo;

int InputData(StudentInfo *);
void PrintInfo1(StudentInfo);
void PrintInfo2(StudentInfo *);

int main(){
  StudentInfo data[N];
  int i, n;

  for (i = 0; i < N; i++){
    if(InputData(&data[i]) == EOF) break;
  }
  n = i;

  printf("構造体の値渡し\n");
  for(i = 0; i < n; i++){
    PrintInfo1(data[i]);
  }
  printf("構造体のアドレス値渡し\n");
  for(i = 0; i < n; i++){
    PrintInfo2(&data[i]);
  }

  return 0;
}


int InputData(StudentInfo *student){
  return scanf("%d %s %d %s %c", &(*student).id, (*student).name, &(*student).grade, (*student).subject, &(*student).record);  
}

void PrintInfo1(StudentInfo student){
  printf("%d\t%s\t%d\t%s\t%c\n", student.id, student.name, student.grade, student.subject, student.record);
}

void PrintInfo2(StudentInfo *student){
  printf("%d\t%s\t%d\t%s\t%c\n", (*student).id, (*student).name, (*student).grade, (*student).subject, (*student).record);
}


