#include <cstdio>
long long a[1000], ans[1000];
int p = 998244353;
int main(int argc, char const *argv[])
{
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i <= n; i++){
		scanf("%d", &a[i]);
		ans[i] = a[i];
	}
	for(int i = 0; i < k; i++)
		printf("0 ");
	for(int i = 0; i < n-k+1; i++){
		int temp = n-i;
		for(int j = 0; j < k; j++){
			ans[i] = ((ans[i]%p)*(temp%p))%p;
			temp--;
		}
		if(i != n-k)
			printf("%lld ", ans[i]);
		else
			printf("%lld\n", ans[i]);
	}
	return 0;
}