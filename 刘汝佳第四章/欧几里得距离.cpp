#include <stdio.h>
typedef struct {double x,y;}point;
double diat(point a, point b){
	return htpot(a.x - b.x, a.y - b.y);
}
int main(){
	struct point a, b;
	double c;
	scanf("%lf %lf %lf %lf",&a.x, &a.y, %b.x , %b.y);
	c = diat(a,b);
	printf("%lf",c);
	return 0;
}