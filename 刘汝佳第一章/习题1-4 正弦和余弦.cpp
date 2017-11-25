#include <stdio.h>
#include <math.h>
int main()
{	
	const double pi = acos(-1.0);
	double n ;
	double a , b ;
	scanf("%lf", &n);
	n = (n / 180) * pi ;
	a = sin(n);
	b = cos(n); 
	printf("%lf %lf" , a , b);
	return 0 ;
}