#include <stdio.h>
int main(int argc, char const *argv[])
{
	long long int a, b;
	while(scanf("%lld %lld", &a, &b) != EOF){
		long long int ans;
		ans = a+b;
		printf("%lld\n", ans);
	}
	return 0;
}