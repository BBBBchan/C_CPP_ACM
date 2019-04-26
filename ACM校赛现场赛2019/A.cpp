#include <cstdio>
int a[105][105];
int visited[105] = {0};
int main(int argc, char const *argv[])
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
			if(j > i && a[i][j] >= 60){
				visited[i] = 1;
				visited[j] = 1;
			}
		}
	}
	for(int i = 0; i<n;i++){
		if(visited[i] == 0)
			ans++;
	}
	printf("%d", ans);
	return 0;
}