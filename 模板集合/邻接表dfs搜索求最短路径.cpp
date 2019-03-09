#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;//dfs最短路 
struct edge{
	int to;
	int len;
};
int n, m;
vector < vector< edge>> G(120);
int totallen= 0, minlen = 1000000;
int visit[120] = {0};
void dfs(int x){
	if(x == n){
		if(totallen < minlen){
			minlen = totallen;
		}
	}
	else{
		for(int i = 0; i < G[x].size(); i++){
			if(!visit[G[x][i].to]){
				visit[G[x][i].to] = 1;
				totallen += G[x][i].len;
				dfs(G[x][i].to);
				visit[G[x][i].to] = 0;
				totallen -= G[x][i].len;
			}
		}
	}
} 
int main(int argc, char const *argv[])
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		edge temp1, temp2;
		scanf("%d %d %d", &temp2.to, &temp1.to, &temp1.len);
		temp2.len = temp1.len;
		G[temp2.to].push_back(temp1);
		G[temp1.to].push_back(temp2);
	}
	dfs(1);
	printf("%d\n", minlen);
	return 0;
}
/*
6 9
1 6 14
1 2 7
1 3 9
6 3 2
3 2 10
3 4 11
2 4 15
5 6 9
4 5 6
*/