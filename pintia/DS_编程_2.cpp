#include <cstdio>
#include <cmath>
#include <cstdlib>
int main(int argc, char const *argv[])
{
	double x1,y1,x2,y2,x3,y3;
	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
	double x = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	double y = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	double z = sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	if(x+y>z && y+z>x && x+z>y){
		double L = x+y+z, s = (x+y+z)/2.0;
		double A = sqrt(s*(s-x)*(s-y)*(s-z));
		printf("L = %.2f, A = %.2lf",L,A);
	}
	else
		printf("Impossible");
	return 0;
}