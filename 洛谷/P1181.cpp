#include <cstdio>
int a[100005];
int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int ans = 1, sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
		if(sum > m){
			sum = a[i];
			ans++;
		}

	}
	printf("%d", ans);
	return 0;
}