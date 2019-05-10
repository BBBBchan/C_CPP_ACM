#include <cstdio>
#include <cmath>
int main(int argc, char const *argv[])
{
	double n, k;
	scanf("%lf %lf", &n, &k);
	long long ans = 0;
	// while(n >= k){
	// 	ans += (n/k)*k;
	// 	int temp = n;
	// 	n -= (n/k)*k;
	// 	n += temp/k;
	// }
	// ans+=n;
	ans = n + ceil(n/(k-1)) - 1;
	printf("%lld\n", ans);
	return 0;
}