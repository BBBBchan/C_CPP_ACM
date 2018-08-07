#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 20005
int fa[maxn];
int n , m, q, p,s;
int r[maxn],ans[maxn];
struct node{
    int u;
    int v;
    int w;
}N[maxn*5];
int cmp1(node a, node b){
    return a.w < b.w;
}
struct query
{
    int limit;
    int num;
}Q[maxn*5];
int cmp2(query a, query b){
    return a.limit < b.limit;
}
int find(int x)
{
    if( fa[x] != x ){
        int f = fa[x];
        fa[x] = find(fa[x]);
        r[x] = (r[x]+r[f])%2;
    }
     return fa[x];
}

void set(int n){
    for(int i = 1; i <= n; i++)
    {
        fa[i] = i;
        r[i] = 1;
    }
}
int get(int x){
    return x*(x-1);
}
void Union(int x,int y)
{
    x=find(x);
    y=find(y);
    if (x!=y)
    {
        p-=get(r[x])+get(r[y]);
        fa[y]=x,r[x]+=r[y];
        p+=get(r[x]);
    }
}
int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &m, &q);
        set(n);
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &N[i].u, &N[i].v, &N[i].w);
        }
        sort(N, N+m, cmp1);
        for(int i = 0; i < q; i++){
            scanf("%d", &Q[i].limit);
            Q[i].num = i;
        }
        sort(Q,Q+q,cmp2);
        p = 0;
        for(int j = 0,i = 0;i <q ; i++){
            for(;j<m;j++){
                if(Q[i].limit>=N[j].w)
                    Union(N[j].u, N[j].v);
                else break;
            }
            ans[Q[i].num] = p;
        }
        for(int i = 0; i < q; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}