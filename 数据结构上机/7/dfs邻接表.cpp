// 邻接表的dfs遍历
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int vis[120] = {0};
int n, m;
struct edge{
	int to, len;
};
vector< vector< edge>> G(120);
void dfs(int i){
	if(vis[i] == 1)
		return;
	else{
		vis[i] = 1;
		printf("%d ", i+1);
		for(int j = 0; j < G[i].size(); j++){
			if(vis[j] == 0)
				dfs(j);
		}
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		edge r1, r2;
		scanf("%d %d %d", &r2.to, &r1.to, &r1.len);
		r2.len = r1.len;
		G[r2.to].push_back(r1);
		G[r1.to].push_back(r2);
	}
	for(int i = 0; i < n; i++){
		dfs(i);
	}
	return 0;
}
/*
6 9
0 1 20
0 2 16
1 4 13
1 2 15
1 5 28
5 4 12
4 3 12
2 3 14
5 3 12
*/