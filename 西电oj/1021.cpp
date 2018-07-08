#include <stdio.h>
#include <math.h>
#define pi acos(-1)
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		double n, x;
		scanf("%lf %lf", &n, &x);
			double ans;
			ans = x*x*n*sin(2*pi/n)/(4*(1-cos(2*pi/n)));
			printf("%.4lf\n", ans);
	}
	return 0;
}