#include <cstdio>
#include <cmath>
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--){
		double a, b, c;
		scanf("%lf%lf%lf", &a, &b, &c);
		if(a*a-2*a*b*c <= 0){
			printf("0\n");
		}
		else{
			double x1 = (a-b*c-sqrt(a*a-2*a*b*c))/(b*b);
			double x2 = (a-b*c+sqrt(a*a-2*a*b*c))/(b*b);
			// printf("%lf %lf\n", x1, x2);
			double ans;
			if(x1*b+c < 0)
				ans = (((4.0*sqrt(2.0*a))/3.0)*x1*sqrt(x1)) + ((2.0*sqrt(2.0*a))/3.0)*(x2*sqrt(x2)-x1*sqrt(x1)) - (b/2.0)*(x2*x2-x1*x1) - c*(x2-x1);
			else
				ans = ((2.0*sqrt(2.0*a))/3.0)*(x2*sqrt(x2)-x1*sqrt(x1)) - (b/2.0)*(x2*x2-x1*x1) - c*(x2-x1);
			if(t != 0)
				printf("%.10lf\n", ans);
			else
				printf("%.10lf", ans);
		}
	}
	return 0;
}