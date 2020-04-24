#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
#define MAXN  1000
struct edge
{
	int to;
	int weight;
};
int d[MAXN], path[MAXN];
int n, m;
vector< vector<edge> > G(MAXN);
bool BellmanFord(int s){
	for(int i = 0; i < MAXN; i++){
		d[i] = 1e9+7;
		path[i] = 1e9+7;
	}
	d[s] = 0;
	path[s] = s;
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < G[j].size(); k++){
				int to = G[j][k].to;
				int w = G[j][k].weight;
				// printf("%d\n", w);
				if(d[j] + w < d[to]){
					d[to] = d[j] + w;
					path[j] = to;
				}
			}
		
		}
		printf("内核d:");
		for(int x = 0; x < n; x++){
			printf("%d ", d[x]);
		}
		printf("\npath:");
		for(int x = 0; x < n; x++){
			printf("%d ", path[x]);
		}
		printf("\n");
	}
	for(int i = 0; i < n; i++){
		for (int j = 0; j < G[i].size(); j++){
			if(d[i] + G[i][j].weight < d[G[i][j].to])
				return false;
		}
	}
	return true;

}

int main(int argc, char const *argv[])
{
	int u, v, w;
	edge r;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &u, &v, &w);
		r.to = v-1;
		r.weight = w;
		G[u-1].push_back(r);
	}
	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < G[i].size(); j++){
	// 		printf("%d %d %d\n", i, G[i][j].to, G[i][j].weight);
	// 	}
	// }
	if(BellmanFord(4)){
	// BellmanFord(0);
		for(int i = 0; i < n; i++)
			printf("%d ", d[i]);
	}
	return 0;
}
/*
5 10
1 2 6
1 3 7
 2 3 8
2 5 -4
2 4 5
3 4 -3
3 5 9
4 2 -2
5 1 2
5 4 7
0 0 0 0 0
*/