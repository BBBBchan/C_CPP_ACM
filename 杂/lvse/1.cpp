#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<cstring>
#include<vector>
#define MAXN 200010
using namespace std;
int n,m,cnt,sum;
int u[MAXN],v[MAXN],low[MAXN],dfn[MAXN],vis[MAXN],cut[MAXN];
vector<int>ma[MAXN];
vector<pair<int,int> >edges;
vector<int>maf[MAXN];
vector<int>maff[MAXN];
map<pair<int,int>,bool>tbook;
int bridge[MAXN][3],sumans=0,cott,color;
int colored[MAXN];
void add(int x,int y)
{
    u[++cnt]=x;v[cnt]=y;   
    ma[x].push_back(cnt);
    u[++cnt]=y;v[cnt]=x;   
    ma[y].push_back(cnt);  
}
void cut_bridge(int cur,int father,int dep,int n){
    int i;
    vis[cur]=1;dfn[cur]=low[cur]=dep;
    int children=0;
    for(i=0;i<ma[cur].size();++i){
        int tmp=ma[cur][i];
        if(vis[v[tmp]]==1&&father!=v[tmp]){
            if(dfn[v[tmp]]<low[cur])
                low[cur]=dfn[v[tmp]];                                   
        }              
        //cout<<"+1s";         
        if(0==vis[v[tmp]]){
            cut_bridge(v[tmp],cur,dep+1,n);
            children++;
            if(low[v[tmp]]<low[cur])low[cur]=low[v[tmp]];
            if((father==-1&&children>1)||(father!=-1&&low[v[tmp]]>=dfn[cur]))
                cut[cur]=true;
            if(low[v[tmp]]>dfn[cur]){bridge[++cott][1]=cur;bridge[cott][2]=v[tmp];sumans++;}             
        }       
    } 
    vis[cur]=2;    
}
void dfs(int now,int tcolor){
   int i;
   colored[now]=tcolor;
   for(i=0;i<maf[now].size();i++){
      int tmpp=maf[now][i];
      if(!colored[tmpp])dfs(tmpp,tcolor);                               
   }     
}
int path,pos;
void dfs2(int now,int dep){
    int i;
    vis[now]=1;
    if(dep>=path){path=dep,pos=now;}
    for(i=0;i<maff[now].size();i++){
       int tmpp=maff[now][i];
       if(!vis[tmpp])dfs2(tmpp,dep+1);                           
    }     
}
int main()
{
   int i,j,k;
   scanf("%d%d",&n,&m);
   for(i=1;i<=m;i++){
      int x,y;
      scanf("%d%d",&x,&y);
      edges.push_back(make_pair(x,y));             
   }
   m=edges.size();
   for(i=0;i<m;i++)
      {
         int x,y;
         x=edges[i].first;
         y=edges[i].second;
         add(x,y);              
      }   
   cut_bridge(1,-1,0,n);
   for(i=1;i<=cott;i++){
      tbook[make_pair(bridge[i][1],bridge[i][2])]=1;
      tbook[make_pair(bridge[i][2],bridge[i][1])]=1;
   }
   for(i=0;i<m;i++){
      if(!tbook[edges[i]]){
          maf[edges[i].first].push_back(edges[i].second);
          maf[edges[i].second].push_back(edges[i].first);                      
      }                 
   }
   for(i=1;i<=n;i++)
      if(!colored[i]){
        color++;
        dfs(i,color);
      }
   for(i=1;i<=cott;i++){
      maff[colored[bridge[i][1]]].push_back(colored[bridge[i][2]]);
      maff[colored[bridge[i][2]]].push_back(colored[bridge[i][1]]);                 
   }
   memset(vis,0,sizeof(vis));
   dfs2(1,0);
   memset(vis,0,sizeof(vis));
   dfs2(pos,0);
   cout<<sumans<<" "<<path;
   //cout<<sumans<<endl;
   //for(i=1;i<=cott;i++){
   //   cout<<bridge[i][1]<<" "<<bridge[i][2]<<endl;
   //}
   //cout<<endl;
   //for(i=1;i<=n;i++)cout<<colored[i]<<endl;
   //system("pause");
   return 0;
}

/*7 7
1 7
1 2
2 3
3 4
4 5
5 6
4 7*/