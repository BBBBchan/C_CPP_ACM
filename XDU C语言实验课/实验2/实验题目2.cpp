#include <stdio.h>
int main(){
	int a, b, c;
	double x1,x2;
	double delta;
	scanf("%d %d %d",&a,&b,&c);
	delta = b*b-4*a*c;
	if(delta < 0)
		printf("No answer");
	else {
		x1 = (-1.0*b + delta)/(2*a);
		x2 = (-1.0*b - delta)/(2*a);
		printf("x1 = %lf, x2 = %lf",x1,x2);
	}
	return 0;
}
