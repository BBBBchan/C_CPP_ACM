#include <cstdio>
#include <iostream>
using namespace std;

int edges[10005][10005];//边
int used[10005];
int minn[10005];//从集合X出发到节点v的最小值
int n,m;
 
int prim(){
    for (int i = 0; i < n; i += 1){
        minn[i] = 1e9+7;
        used[i] = false;
    }
    minn[0] = 0;
    int res = 0;
    while (1){
        int v = -1;
        //从不属于X的顶点中找到从X到其权值最小的顶点
        for(int i = 0; i < n; i++){
            if(!used[i] && (v == -1 || minn[i] < minn[v])) {
                v = i;
            }
        }
        if(v == -1){
            break;
        }
        used[v] = true;             //加入集合
        res += minn[v];
        //在此顶点基础上对X到其他顶点的最小值进行更新
        for (int i = 0; i < n; i += 1){
            minn[i] = min(minn[i],edges[v][i]);
        }
    }
    return res;
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
    int ans = prim();
    printf("%d\n", ans);
    return 0;
}