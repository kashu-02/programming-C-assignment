#include <stdio.h>

#define MAX_ST_NUM 50                   /* 学生数の最大値 */
#define MAX_SCORE 110                   /* 110点満点 */
int student_id[MAX_ST_NUM];             /* 学籍番号  */
int abs_score[MAX_ST_NUM];              /* 点数 (補正前) */
char abs_grade[MAX_ST_NUM];             /* 補正前の評価 (A - F) */
int rel_score[MAX_ST_NUM];              /* 点数 (補正後) */
char rel_grade[MAX_ST_NUM];             /* 補正後の評価 (A - F) */
int grade_dist[2][5];                   /* 評価の分布 [0]:補正前, [1] 補正後 */
                                        /* 例 grade_dist[0][0] 補正前の Fの人数 */
char cgrade[5]={'F','D','C','B','A'};   /* 評価（A - F） */
int num_student;                        /* 実際に成績を読み込んだ学生の数 */
double abs_ave=0.0;                     /* 平均点（補正前） */
double rel_ave=0.0;                     /* 平均点（補正後） */


int calib(int); /* 満点の補正を行う。内部では実数で計算し、小数点第１位で四捨五入した整数を返す */
void adjust_score(void);
void print_grade(void);
char scoreToGrade(int);
void grading(void);
int getDistIndex(char);
void print_grade(void);
void print_stat(void);

int main(){
  /* 標準入力から学籍番号と点数を読みこむコードをここに書く。 */
  num_student = 0;
  while(scanf("%d %d", &student_id[num_student], &abs_score[num_student]) != EOF) num_student++;

  adjust_score();  /* 点数を補正し、補正後の点数の配列に書きこむ。*/
  grading();  /* 補正前・補正後の各学生の評価(A～F)を決定し、それぞれ
                      平均点と評価分布を求める*/
  print_grade();   /* 補正前と後の点数と評価を表示。実行例参照 */
  print_stat();    /* 統計と評価分布を表示。フォーマットは実行例参照 */
  return 0;
}

int calib(int x){
  int ans;
  ans = ((double) x * ((double) 100 / 110)) + 0.5;
  return ans;
}

void adjust_score(){
  int i;
  for (i =0; i < num_student; i++){
    rel_score[i] = calib(abs_score[i]);
  }
}

void grading(){
  int i, j, abs_sum = 0, rel_sum = 0;
  for (i = 0; i < 2; i++){ //初期化
    for (j = 0; j < 5; j++){
      grade_dist[i][j] = 0;
    }
  }
    for (i = 0; i < num_student; i++)
    {
      abs_grade[i] = scoreToGrade(abs_score[i]);
      rel_grade[i] = scoreToGrade(rel_score[i]);
      abs_sum += abs_score[i];
      rel_sum += rel_score[i];
      grade_dist[0][getDistIndex(abs_grade[i])]++;
      grade_dist[1][getDistIndex(rel_grade[i])]++;
    }
  abs_ave = (double) abs_sum / num_student;
  rel_ave = (double) rel_sum / num_student;
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
  }else if(score >= 80 && score <= 110){
    return 'A';
  }
}

int gradeToPoint(char grade){
  if(grade == 'F' || grade == 'D'){
    return 0;
  }else if(grade == 'C'){
    return 2;
  }else if(grade == 'B'){
    return 3;
  }else if(grade == 'A'){
    return 4;
  }
}
int getDistIndex(char c){
  if(c == 'A'){
    return 4;
  }else if(c == 'B'){
    return 3;
  }else if(c == 'C'){
    return 2;
  }else if(c == 'D'){
    return 1;
  }else if(c == 'F'){
    return 0;
  }
}

void print_grade(){
  int i;
  printf("ID\t点数\t評価\t点数\t評価\n");
  printf("\t(補正前)\t補正後\n");
  printf("-----------\n");
  for (i = 0; i < num_student; i++){
    printf("%d\t%d\t%c\t%d\t%c\n", student_id[i], abs_score[i], abs_grade[i], rel_score[i], rel_grade[i]);
  }
  printf("-----------\n");
}

void print_stat(){
  int i;
  printf("統計\n");
  printf("学生数 %d人 補正前平均点 %.1f点 補正後平均点 %.1f点\n", num_student, abs_ave, rel_ave);
  printf("評価分布\n");
  printf("補正前　");
  for (i = 4; i >= 0; i--){
    printf("%c %d ", cgrade[i], grade_dist[0][i]);
  }
  printf("\n");
  printf("補正後　");
  for (i = 4; i >= 0; i--){
    printf("%c %d ", cgrade[i], grade_dist[1][i]);
  }
  printf("\n");
}
