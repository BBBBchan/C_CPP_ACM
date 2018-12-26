#include <cstdio>
#include <cmath>
int main(int argc, char const *argv[])
{
	double money, year, rate;
	scanf("%lf %lf %lf", &money, &year, &rate);
	double ans;
	ans = money*pow((1+rate),year) -money;
	printf("interest = %.2f\n", ans);
	return 0;
}