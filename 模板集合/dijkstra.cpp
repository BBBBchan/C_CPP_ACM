// Dij求最短路
#include <cstdio>
#include <iostream>
using namespace std;
int edges[10005][10005];
int d[10005];
bool used[10005];
int n, m;
void Dijkstra(int s){
    for(int i = 0; i < n; i++){
        d[i] = 1e9+7;
        used[i] = false;
    }
    d[s] = 0;
    while(1){
        int v = -1;
        for(int u = 0; u < n; u++){
            if(!used[u] && (v == -1 || d[u] < d[v]))
                v = u;
        }
        if(v == -1)
            break;
        used[v] = true;
        for(int u = 0; u < n; u++){
            d[u] = min(d[u], d[v] + edges[v][u]);
        }
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            edges[i][j] = 1e9+7;
    for(int i = 0; i < m; i++){
        int u, v, d;
        scanf("%d %d %d", &u, &v, &d);
        edges[u-1][v-1] = d;
        edges[v-1][u-1] = d;
    }
    Dijkstra(0);
    for(int i = 0; i < n; i++)
        printf("%d ", d[i]);
    return 0;
}
/*
5 7
1 2 2
1 4 10
2 4 7
2 3 3
3 4 6
3 5 4
4 5 5
*/