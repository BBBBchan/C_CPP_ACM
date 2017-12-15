#include <stdio.h>
#define pi 3.1415926536
int main(){
	double r, s, S, v;
	scanf("%lf",&r);
	s = pi * r * r;
	S = 4 * s;
	v = (4/3)*pi*r*r*r;
	printf("%.10f\n%.10f\n%.10f\n",s,S,v);
	return 0;
}
