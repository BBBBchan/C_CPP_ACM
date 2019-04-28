#include <cstdio>
#include <cmath>
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--){
		float a, b;
		scanf("%f %f", &a, &b);
		if(a > 0){
			if(a*a + 4*a*b == 0){
				if(a*(2*b+a)/2 >= 0)
					printf("1\n%.0f\n", (2*b+a)/2);
			}
			else if(a*a + 4*a*b > 0){
				int kase1 = 1, kase2 = 1;
				float ans1 = (2*b + a + sqrt(a*a + 4*a*b))/2;
				float ans2 = (2*b + a - sqrt(a*a + 4*a*b))/2;
				if(ans1 * a < 0)
					kase1 = 0;
				if(ans2 * a < 0)
					kase2 = 0;
				if(kase2 == 1 && kase1 == 1)
					printf("2\n%.0f %.0f\n", ans2, ans1);
				else if(kase2 == 0 && kase1 == 1)
					printf("1\n%.0f\n", ans1);
				else if(kase2 == 1 && kase1 == 0)
					printf("1\n%.0f\n", ans2);
			}
		}
		else if(a < 0){
			if(a*a - 4*a*b == 0){
				if(a * (2*b-a)/2 >= 0)
					printf("1\n%.0f\n", (2*b-a)/2);
			}
			else if(a*a - 4*a*b > 0){
				int kase1 = 1, kase2 = 1;
				float ans1 = (2*b - a + sqrt(a*a - 4*a*b))/2;
				float ans2 = (2*b - a - sqrt(a*a - 4*a*b))/2;	
				if(ans1 * a < 0)
					kase1 = 0;
				if(ans2 * a < 0)
					kase2 = 0;
				if(kase2 == 1 && kase1 == 1)
					printf("2\n%.0f %.0f\n", ans2, ans1);
				else if(kase2 == 0 && kase1 == 1)
					printf("1\n%.0f\n", ans1);
				else if(kase2 == 1 && kase1 == 0)
					printf("1\n%.0f\n", ans2);		
			}
		}
		else if(a == 0)
			printf("1\n%.0f\n", b);
	}
	return 0;
}