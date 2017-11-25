#include <stdio.h>
int main()
{
	int a, b, c, kase = 0;
	while(scanf("%d %d %d", &a, &b, &c ) == 3 && (a || b || c)){
		double x = 0.0;
		x = (double) a / b ;
		printf("Case %d: %.*f", ++kase, c, x);
	} 
	return 0;
}