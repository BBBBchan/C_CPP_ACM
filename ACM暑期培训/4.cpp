#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
LL qmodx(LL a,LL b,LL c)
{
    a%=c,b%=c;
    if(c<=1000000000) return a*b%c;
    return (a*b-(LL)(a/(long double)c*b+1e-8)*c+c)%c;//a*b%c=a*b-floor(a*b/mod)*mod 
}//O（1）快速乘取模问题 
LL qmod(LL a,LL b,LL c)//二进制的思想 
{
    LL res=1;
    while(b)
    {
        if(b&1) res=qmodx(res,a,c)%c;
        b>>=1;
        a=qmodx(a,a,c)%c;
    }
    return res;
}

const int MAX_V = 205;
 
vector<int> G[MAX_V]; // 图
int V;                  // 顶点数
int color[MAX_V];       // 顶点i的颜色 1 或 -1
 
// 把顶点染成1或-1
bool dfs(int v, int c)
{
    color[v] = c; // 把顶点v染成颜色c
    for (int i = 0; i < G[v].size(); ++i) {
        if (color[G[v][i]] == c) return false;
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -1*c)) return false;
    }
    return true;
}
 
void solve()
{
    for (int i = 0; i < V; ++i) {
        if (color[i] == 0) {
            if (!dfs(i, 1)) {
                puts("0");
                return ;
            }
        }
    }
    LL count = 0;
    for(int i = 0; i < V; i++){
        if(color[i] == 1)
            count++;
    }
    printf("%lld\n", (qmod(2,count-1,998244353)+qmod(2,V-count+1,998244353))%998244353);
}
 
int main()
{
    int E;
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &V, &E);
        int a, b;
        for (int i = 0; i < V; ++i) G[i].clear();           
        memset(color, 0, sizeof color);
        for (int i = 0; i < E; ++i) {
            scanf("%d%d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        solve();
    }
    return 0;
}