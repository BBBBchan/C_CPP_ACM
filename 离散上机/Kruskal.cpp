#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,m,i,j,u,v,total;
struct edge{
    int start, to, val;
}edges[2000005];

int f[100000];
int ans=0;
int find(int x)//并查集
{
    if (f[x]==x) 
        return x; 
    else{
        f[x]=find(f[x]);
        return f[x];
    }
}
bool cmp(edge a,edge b)
{
    return a.val < b.val;
}
void kruskal()
{
    for(int i = 1; i <= m; i++){
        u=find(edges[i].start);
        v=find(edges[i].to);
        if(u==v) 
            continue;//判断在不在同一个并查集里面，在就下一个循环
        ans += edges[i].val;//不在，就加上
        f[u] = v;       //写入并查集
        total++;
        if(total == n-1)
            break;
    }
} 
int main()
{
    scanf("%d %d",&n,&m);
    for(i = 1; i <= n; i++)
        f[i]=i;         //初始化并查集
    for(i = 1; i <= m; i++){
        scanf("%d %d %d",&edges[i].start, &edges[i].to, &edges[i].val);
    }
    sort(edges+1,edges+m+1,cmp);
    kruskal();
    printf("%d", ans);
    return 0;
}