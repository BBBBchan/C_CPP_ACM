#include <cstdio>
int a[10] = {0};
int main(int argc, char const *argv[])
{
	long long n,m;
	scanf("%lld %lld", &n, &m);
	for(long long i = n; i <= m; i++){
		long long temp = i;
		while(temp != 0){
			a[temp%10]++;
			temp/=10;
		}
	}
	for(int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	return 0;
}