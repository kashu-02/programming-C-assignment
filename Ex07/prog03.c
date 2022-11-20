#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUBJECT_NUM 4 /* 科目数 */

#define N 20

typedef struct{
	char id[10];            /* 学籍番号 */
	char name[10];          /* 名前 */
	int score[SUBJECT_NUM]; /* 各点数 */
	int sum;                /* 合計点 */
	double ave;             /* 平均 */
	char grade;             /* 判定 */
} Record;

void input(char *);
void SumAve(Record *);
void Grading(Record *);
void output(void);
void search(void);

Record scores[N];
int n;

int main(int argc, char *argv[]){
  

  if(argc != 2){
    fprintf(stderr, "Error!  Usage: %s datafilename\n", argv[0]);
    exit(1);
  }

  input(argv[1]); // Input to scores array

  output(); // Output scores array

  search(); // Search scores array

  printf("\n");

  return 0;
}

void input(char *filename){
  FILE *fp;
  int i, j;
  if((fp = fopen(filename, "r")) == NULL){
    fprintf(stderr, "Cannot open file.\n");
    exit(1);
  }
  for(i = 0; i < N; i++){
    if(fscanf(fp, "%s %s", &scores[i].id, &scores[i].name) == EOF)
      break;
    for(j = 0; j < SUBJECT_NUM; j++){
      fscanf(fp, "%d", &scores[i].score[j]);
    }
    SumAve(&scores[i]);
    Grading(&scores[i]);
  }
  n = i;
  fclose(fp);
}

void SumAve(Record *data){
  int i;
  data->sum = 0;
  for(i = 0; i < SUBJECT_NUM; i++){
    data->sum += data->score[i];
  }
  data->ave = data->sum / (double)SUBJECT_NUM;
}

void Grading(Record *data){
  if(data->ave >= 80){
    data->grade = 'A';
  }else if(data->ave >= 65){
    data->grade = 'B';
  }else if(data->ave >= 50){
    data->grade = 'C';
  }else if(data->ave >= 35){
    data->grade = 'D';
  }else{
    data->grade = 'F';
  }
}

void output(void){
  int i;
  for(i = 0; i < n; i++){
    printf("%s %s  %d %d %d %d %d %.1f %c\n", scores[i].id, scores[i].name, scores[i].score[0], scores[i].score[1], scores[i].score[2], scores[i].score[3], scores[i].sum, scores[i].ave, scores[i].grade);
  }
}

void search(void){
  int hit = 0;
  while(1){
  char query[10];
  int i;
  printf("Input a student name/ID:");
  if(scanf("%s", query) == EOF)
    break;
  ;
  for(i = 0; i < n; i++){
    if(strcmp(query, scores[i].id) == 0 || strcmp(query, scores[i].name) == 0){
      printf("%s %s  %d %d %d %d %d %.1f %c\n", scores[i].id, scores[i].name, scores[i].score[0], scores[i].score[1], scores[i].score[2], scores[i].score[3], scores[i].sum, scores[i].ave, scores[i].grade);
      hit = 1;
    }
  }
  if(hit != 1) printf("This student does not exist!\n");
  }
}