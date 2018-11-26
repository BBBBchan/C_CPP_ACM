#include <stdio.h>
int main(int argc, char const *argv[])
{
	double n;
	while(scanf("%lf", &n) != EOF && n != 0.0){
		double ans = 0.5;
		int count = 1;
		while(ans < n){
			count++;
			ans = ans + 1.0/(count+1);
		}
		printf("%d card(s)\n", count);
	}
	return 0;
}
