#include <cstdio>
long long int b[200005], a[200005];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n/2; i++){
		scanf("%lld", &b[i]);
	}
	a[1] = 0;
	a[n] = b[1];
	for(int i = 2; i <= n/2; i++){
		if(b[i]-a[i-1] <= a[n-i+2]){
			a[i] = a[i-1];
			a[n-i+1] = b[i]-a[i-1];
		}
		else{
			a[i] = b[i]-a[n-i+2];
			a[n-i+1] = b[i]-a[i];
		}
	}
	for(int i = 1; i <= n; i++)
		printf("%lld ", a[i]);
	return 0;
}