#include <stdio.h>
#include <math.h>

typedef struct{
	double x; /* x座標 */
	double y; /* y座標 */
}XY; /* 平面上の点 */
 
typedef struct{
	XY center;
	XY p;
	double r;
} CIRCLE; /* centerを中心点、pを円周上の点、rを半径とする円 */

CIRCLE input1(void);   /* データを読み込んだ構造体を戻す */
void input2(CIRCLE *); /* 構造体のポインタを渡し、そこにデータを読み込む */
double getRadius(CIRCLE *); /* 半径を求める */

int main(){
	CIRCLE c;
	printf("データの入力（構造体を返す関数）:\n");
	c = input1();
	c.r = getRadius(&c);
	printf("input1: length, area : %f, %f\n", (double)c.r*2*M_PI, (double)c.r*c.r*M_PI);

	printf("データの入力（構造体のポインタを渡す関数）:\n");
	input2(&c);
	c.r = getRadius(&c);
	printf("input2: length, area : %f, %f\n", (double)c.r*2*M_PI, (double)c.r*c.r*M_PI);
}


CIRCLE input1(void){
	CIRCLE circle;
  scanf("%lf %lf %lf %lf", &circle.center.x, &circle.center.y, &circle.p.x, &circle.p.y);
	return circle;
}

void input2(CIRCLE *circle){
	scanf("%lf %lf %lf %lf", &circle->center.x, &circle->center.y, &circle->p.x, &circle->p.y);
}

double getRadius(CIRCLE *circle){
	return sqrt((circle->p.x - circle->center.x) * (circle->p.x - circle->center.x) + (circle->p.y - circle->center.y) * (circle->p.y - circle->center.y));
}