#include <bits/stdc++.h>
#define MAXN 200010
//#define INF 2147483647
using namespace std;
struct Edge {
  int u, v, w;
};
vector<Edge> edges;
vector<int>g[200010];
vector<pair<int,int> >g2[MAXN];
int color[200010],dfn[200010],low[200010],stackk[200010],vis[200010];
int inDeg[200010];
int dp[200010];
int deep,top,N,sum,ans;
void topsort(){
    queue<int> q;
    for(int i=1;i<=N;i++){
        if(inDeg[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int i=0;i<g2[tmp].size();i++){
            int v = g2[tmp][i].first;
            int c = g2[tmp][i].second;
            inDeg[v]--;
            if(inDeg[v]==0){
                q.push(v);
            }
            dp[v]= max(dp[v], dp[tmp] + c);
        }
        g2[tmp].clear();
    }
}
void tarjan(int u)
{
    dfn[u]=++deep;
    low[u]=deep;
    vis[u]=1;
    stackk[++top]=u;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);           
        }        
        else
        {
            if(vis[v])
            {
               low[u]=min(low[u],low[v]);          
            }    
        }
    }   
    if(dfn[u]==low[u])
    {
        color[u]=++sum;
        vis[u]=0;
        while(stackk[top]!=u)
        {
            color[stackk[top]]=sum;                
            vis[stackk[top--]]=0;    
        } 
        top--;             
    } 
}
 void add(int x,int y)
{
    g[x].push_back(y);    
}
int solve(int n, const vector<Edge> &edges) {
    /**********  Begin  **********/
    N = n;
    int i,j,k;
    for(i=0;i<edges.size();i++){
       add(edges[i].u,edges[i].v);                            
    }
    for(i=1;i<=n;i++){
       if(!dfn[i])
           tarjan(i);                  
    }
    for(i=0;i<edges.size();i++){
       if(color[edges[i].u]!=color[edges[i].v]){
            g2[color[edges[i].u]].push_back(make_pair(color[edges[i].v],edges[i].w)); 
            inDeg[color[edges[i].v]]++;                                       
       }                            
    }
    topsort();
    for(i=1;i<=n;i++)
      ans=max(ans,dp[i]);
    return ans;
}
int main()
{
    int n = 5;
    for(int i = 0; i < 6; i++){
        Edge temp;
        cin >> temp.u;
        cin >> temp.v;
        cin >> temp.w;
        edges.push_back(temp);
    }
    cout << solve(n,edges) << endl;
    return 0;
}