#include <cstdio>
int a[105];
int main(int argc, char const *argv[])
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++){
		int kase = 0;
		for(int j = 0; j < n; j++){
			if(j == i)
				continue;
			for(int k = j; k < n; k++){
				if(k == j || k == i)
					continue;
				else if(a[k]+a[j] == a[i]){
					kase = 1;
					ans++;
					break;
				}
			}
			if(kase)
				break;
		}
	}
	printf("%d", ans);
	return 0;
}