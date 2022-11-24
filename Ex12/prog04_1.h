
typedef struct {
  double x;
  double y;
} Point;

typedef struct {
	Point vertex[3];
  double area;
} Triangle;

Triangle InputTriangle(int);

Triangle CalcArea(Triangle *);