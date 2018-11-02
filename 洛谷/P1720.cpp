#include <cstdio>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	long long int a[100] = {0,1,1};
	for(int i = 3; i<=n; i++){
		a[i] = a[i-1]+a[i-2];
	}
	printf("%lld.00", a[n]);
	return 0;
}