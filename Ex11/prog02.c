#include <stdio.h>
#include <math.h>

typedef struct {
  double  x; /* x座標 */
  double  y; /* y座標 */
} Point;

Point rotate1(double, Point, Point);
void  rotate2(double, Point *, Point *);
Point rotate3(double, Point *);
void rotate4(double, Point *);

int main()
{
  double rad, deg;
  Point c = {1.0, 0.0}, a = {3.0, 2.0}; /* 中心と回転対象の点 */
  Point point1[2], point2[3];
  Point b1, b2, b3; /* 結果を入れる構造体 */

  printf("回転角 [度] を入力してください\n");
  scanf("%lf", &deg);
  rad = deg*M_PI/180;
  printf("回転角 %f [deg] (%f [rad])\n", deg, rad);
  
  /*
   * ここに関数呼び出しおよび関連するコードを書く
   */
  b1 = rotate1(rad, c, a);
  b2 = a;
  rotate2(rad, &c, &b2);

  point1[0].x = c.x;
  point1[0].y = c.y;
  point1[1].x = a.x;
  point1[1].y = a.y;
  b3 = rotate3(rad, point1);

  point2[0].x = c.x;
  point2[0].y = c.y;
  point2[1].x = a.x;
  point2[1].y = a.y;
  rotate4(rad, point2);

  printf("Center  : %f %f\n", c.x, c.y);
  printf("Point A : %f %f\n", a.x, a.y);
  printf("rotate1 : %f %f\n", b1.x, b1.y);   /* 関数１の結果を出力 */
  printf("rotate2 : %f %f\n", b2.x, b2.y);   /* 関数２の結果を出力 */
  printf("rotate3 : %f %f\n", b3.x, b3.y);
  printf("rotate4 : %f %f\n", point2[2].x, point2[2].y);

  return 0;
}

/*
 * ここにプロトタイプに合わせた rotate1関数の中身を書く
 */
Point rotate1(double rad, Point center, Point point){
  Point result;
  result.x = (point.x - center.x) * cos(rad) + (point.y - center.y) * (-sin(rad)) + center.x;
  result.y = (point.y - center.y) * sin(rad) + (point.y - center.y) * cos(rad) + center.y;
  return result;
}

/*
 * ここにプロトタイプに合わせた rotate2関数の中身を書く
 */
void  rotate2(double rad, Point *center, Point *point){
  Point result;
  result.x = (point->x - center->x) * cos(rad) - (point->y - center->y) * sin(rad) + center->x;
  result.y = (point->y - center->y) * sin(rad) + (point->y - center->y) * cos(rad) + center->y;
  point->x = result.x;
  point->y = result.y;
}


Point rotate3(double rad, Point *point){
  Point result;
  result.x = ((point + 1)->x - point->x) * cos(rad) - ((point + 1)->y - point->y) * sin(rad) + point->x;
  result.y = ((point + 1)->y - point->y) * sin(rad) + ((point + 1)->y - point->y) * cos(rad) + point->y;
  return result;
}

void rotate4(double rad, Point *point){
  (point + 2)->x = ((point + 1)->x - point->x) * cos(rad) - ((point + 1)->y - point->y) * sin(rad) + point->x;
  (point + 2)->y = ((point + 1)->y - point->y) * sin(rad) + ((point + 1)->y - point->y) * cos(rad) + point->y;
}
