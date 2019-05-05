#include <cstdio>
int main(int argc, char const *argv[])
{
	long long int sum=1,x, n;
	scanf("%lld %lld", &x, &n);
	for(int i = 0; i < n; i++){
		sum += sum*x;
	}
	printf("%lld", sum);
	return 0;
}