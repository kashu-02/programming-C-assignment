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

typedef struct{
	CIRCLE circle;
	double h;
}CYLINDER;

CYLINDER input1(void);   /* データを読み込んだ構造体を戻す */
void input2(CYLINDER *); /* 構造体のポインタを渡し、そこにデータを読み込む */
double getRadius(CYLINDER *); /* 半径を求める */

int main(){
	CYLINDER c1, c2;
	double length, area;
	printf("データの入力（構造体を返す関数）:\n");
	c1 = input1();
	c1.circle.r = getRadius(&c1);
	length = (double)c1.circle.r*2*M_PI;
	area = (double)c1.circle.r * c1.circle.r * M_PI;
	printf("input1: length, area : %f, %f\n", (double)c1.circle.r * 2 * M_PI, (double)c1.circle.r * c1.circle.r * M_PI);
	printf("input1: surface, volume : %f, %f\n", (c1.h*length)+(2*area), c1.h*area);
	printf("データの入力（構造体のポインタを渡す関数）:\n");
	input2(&c2);
	c2.circle.r = getRadius(&c2);
	length = (double)c2.circle.r*2*M_PI;
	area = (double)c2.circle.r * c2.circle.r * M_PI;
	printf("input2: length, area : %f, %f\n", (double)c2.circle.r * 2 * M_PI, (double)c2.circle.r * c2.circle.r * M_PI);
	printf("input2: surface, volume : %f, %f\n", (c2.h*length)+(2*area), c2.h*area);
}


CYLINDER input1(void){
	CYLINDER cylinder;
	printf("円柱底面の円の中心座標(x, y): ");
	scanf("%lf %lf", &cylinder.circle.center.x, &cylinder.circle.center.y);
	printf("円柱底面の円周上の1点の座標(x, y): ");
	scanf("%lf %lf", &cylinder.circle.p.x, &cylinder.circle.p.y);
	printf("円柱の高さh: ");
	scanf("%lf", &cylinder.h);
	return cylinder;
}

void input2(CYLINDER *cylinder){
	printf("円柱底面の円の中心座標(x, y): ");
	scanf("%lf %lf", &(*cylinder).circle.center.x, &(*cylinder).circle.center.y);
	printf("円柱底面の円周上の1点の座標(x, y): ");
	scanf("%lf %lf", &(*cylinder).circle.p.x, &(*cylinder).circle.p.y);
	printf("円柱の高さh: ");
	scanf("%lf", &(*cylinder).h);
}

double getRadius(CYLINDER *cylinder){
	return sqrt((cylinder->circle.p.x - cylinder->circle.center.x) * (cylinder->circle.p.x - cylinder->circle.center.x) + (cylinder->circle.p.y - cylinder->circle.center.y) * (cylinder->circle.p.y - cylinder->circle.center.y));
}