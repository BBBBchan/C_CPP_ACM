#include <stdio.h>
#include <math.h>
double pi = 3.1415926;
int main(int argc, char const *argv[])
{
	int n;
	double x,y,s;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lf %lf", &x, &y);
		s = (pi/2)*(x*x+y*y);
		int ans = s/50.0;		
		printf("Property %d: This property will begin eroding in year %d.\n", i, ans+1);
	}
	printf("END OF OUTPUT.");
	return 0;
}
