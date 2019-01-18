// 邻接矩阵的dfs遍历
#include <cstdio>
int a[100][100];
int vis[100] = {0};
int n, m;
void dfs(int i){
	if(vis[i] == 1)
		return;
	else{
		vis[i] = 1;
		printf("%d ", i+1);
		for(int j = 0; j < n; j++){
			if(a[i][j] == 1)
				dfs(j);
		}
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	for(int i = 0; i < n; i++){
		dfs(i);
	}
	return 0;
}
/*
7 12 
0 0 1 0 0 0 0
1 0 0 0 0 0 0  
0 1 0 0 0 1 0 
0 1 1 0 1 0 0 
0 1 0 0 0 0 0 
0 0 0 1 0 0 0 
0 0 0 1 1 1 0
 */