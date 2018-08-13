#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n, k, ans;
char a[15][15];
int vis[15];
void dfs(int x, int num){
	if(num >= k){
		ans++;
		return;
	}
	for(int i = x; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!vis[j] && a[i][j] == '#'){
				vis[j] = 1;
				dfs(i+1,num+1);
				vis[j] = 0;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	while(scanf("%d %d", &n, &k)!= EOF){
		if(n == k && n == -1)
			break;
		ans = 0;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		dfs(0,0);
		printf("%d\n", ans);
	}
	return 0;
}