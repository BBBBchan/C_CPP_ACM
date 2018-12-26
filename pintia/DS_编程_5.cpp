#include <cstdio>
int main(int argc, char const *argv[])
{
	int n;
	float a, sum = 0,max = -1e6, min = 1e6;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%f", &a);
		if(a > max)
			max = a;
		if (a < min)
			min = a;
		sum += a;
	}
	printf("average = %.2f\n", sum/n);
	printf("max = %.2f\n", max);
	printf("min = %.2f\n", min);
	return 0;
}