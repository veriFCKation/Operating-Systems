#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct Point{
	double x, y;
} Point;

double distance(Point A, Point B){
	return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}

double area(Point A, Point B, Point C){
	return 0.5*(fabs(A.x*B.y - B.x*A.y + B.x*C.y - C.x*B.y + C.x*A.y - A.x*C.y));
}

int main(void){

Point a, b, c;
a.x = 2.5;
a.y = 6;
b.x = 1;
b.y = 2.2;
c.x = 10;
c.y = 6;
printf("AB distatnce is %f\n", distance(a, b));
printf("Triangle area is %f\n", area(a, b, c));

return 0;
}
