#include <cstdio>
int a[10005][10005];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			if(a[i][k] == 1){
				for(int j = 1; j <= n; j++){
					a[i][j] = (a[i][j] || a[k][j]);
				}
			}
		}
	}
	printf("\n");
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}