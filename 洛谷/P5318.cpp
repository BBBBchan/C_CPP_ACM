// 邻接表的dfs遍历
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int vis[100005] = {0};
int n, m;
struct edge{
	int to, len;
};
queue <int> qe;
vector< vector< edge> > G(1000000);

void dfs(int i){
	if(vis[i] == 1)
		return;
	else{
		vis[i] = 1;
		printf("%d ", i);
		for(int j = 0; j < G[i].size(); j++){
			if(vis[G[i][j].to] == 0)
				dfs(G[i][j].to);
		}
	}
}
void bfs(int i){
	int cur;
	while(!qe.empty()){
		cur = qe.front();
		if(vis[cur] == 0){
			vis[cur] = 1;
			qe.pop();
			printf("%d ", cur);
			for(int j = 0; j < G[cur].size(); j++){
				if(vis[G[cur][j].to] == 0)
					qe.push(G[cur][j].to);
			}
		}
		else
			qe.pop();
	}
}
bool cmp(edge a, edge b){
	return a.to < b.to;
}
int main(int argc, char const *argv[])
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		int from, to;
		scanf("%d %d", &from, &to);
		edge r;
		r.to = to;
		G[from].push_back(r);
	}
	for (int i = 1; i <= n; ++i){
		sort(G[i].begin(),G[i].end(),cmp);
	}
	dfs(1);
	memset(vis,0,sizeof(vis));
	printf("\n");
	// for(int i = 1; i <= n; i++){
	// 	if(vis[i] == 0){
	// 		qe.push(i);
	// 		bfs(i);
	// 	}
	// }
	qe.push(1);
	bfs(1);
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
8 9
1 3
1 2
1 4
2 5
2 6
3 7
4 7
4 8
7 8
*/