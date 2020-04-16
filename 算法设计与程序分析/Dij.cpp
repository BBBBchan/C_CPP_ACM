// Dij求最短路
/*Dijkstra求最短路问题，使用邻接矩阵存图，注意双向，使用方法：Dijkstra(s)可以求出s到其他所有点的最短路径，并存在d数组中*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 1000
int n,m;
struct edge
{
    int to;
    int weight;
};
vector< vector<edge> > G(MAXN);
int visited[MAXN];
int d[MAXN];
void Dijkstra(int s){
    for(int i = 0; i < n; i++){
        d[i] = 1e9+7;
    }
    d[s] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, min = 1e9+7;
        for(int j = 0; j < n; j++){
            if(!visited[j] && d[j] < min){
                u = j;
                min = d[j];
            }
        }
        if(u == -1)
            return;
        visited[u] = 1;
        for(int j = 0; j < G[u].size(); j++){
            int to = G[u][j].to;
            int weight = G[u][j].weight;
            if(!visited[to] && d[u] + weight < d[to]){
                d[to] = d[u] + weight;
            }
        }
    }
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
    Dijkstra(0);
    for(int i = 0; i < n; i++){
        printf("%d ", d[i]);
    }
    return 0;
}

/*
5 10
1 2 10
1 3 5
2 4 1
2 3 2
3 2 3
3 4 9
3 5 2
4 5 4
5 1 7
5 4 6
*/