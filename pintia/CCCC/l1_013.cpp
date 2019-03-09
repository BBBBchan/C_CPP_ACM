#include <cstdio>
int main(int argc, char const *argv[])
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int temp = 1;
		for(int j = 1; j <= i; j++){
			temp *= j;
		}
		ans+=temp;
	}
	printf("%d", ans);
	return 0;
}