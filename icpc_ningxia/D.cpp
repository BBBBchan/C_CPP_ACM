#include <cstdio>
int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		double n, m;
		scanf("%lf %lf", &n, &m);
		printf("Case #%d: ", i);
		if(n == 1)
			printf("1.000000 ");
		else
			printf("0.500000 ");
		printf("%.6lf\n", (m+1)/(2*m));
	}
	return 0;
}
