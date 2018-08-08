#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
int pond[10010];
struct edge
{
    int next;
    int to;
}store[200010];

int head[10010],cnt,degree[10010];
bool vist[10010],cut_off[200010];
long long int sum;
int num;
queue <int> qe;
void addedge(int a,int b)
{
   store[cnt].to=b;
   store[cnt].next=head[a];
   head[a]=cnt++;
}
void bfs()
{
    int tmp,cur,v;
    while(!qe.empty())
    {
      cur=qe.front();
      qe.pop();
      tmp=head[cur];
      while(~tmp)
      {
          v = store[tmp].to;
          if(degree[v])
          {
              cut_off[tmp]=cut_off[tmp^1]=1;
              degree[v]--;
              if(degree[v]==1)
              {
                  qe.push(v);
                  degree[v]=0;
              }
          }
          tmp=store[tmp].next;
      }
    }
}

void dfs(int x)
{
   int tmp,v;
   vist[x]=1;
   tmp=head[x];
   while(tmp!=-1)
   {
     if(!cut_off[tmp])
     {
         v=store[tmp].to;
         if(!vist[v])
         {
             num++;
             sum+=pond[v];
             dfs(v);
         }
     }
     tmp=store[tmp].next;
   }
}
int main()
{
    int t,p,m,u,v;
    long long  ans;
    scanf("%d",&t);
    while(t--)
    {
      scanf("%d%d",&p,&m);
      memset(head,-1,sizeof(head));
      memset(degree,0,sizeof(degree));
      memset(vist,0,sizeof(vist));
      memset(cut_off,0,sizeof(cut_off));
      cnt=0,ans=0;
      for(int i=1;i<=p;i++)
          scanf("%d",&pond[i]);
      for(int i=1;i<=m;i++)
      {
          scanf("%d %d",&u,&v);
          addedge(u,v);
          addedge(v,u);
          degree[u]++;
          degree[v]++;
      }
      for(int i=1;i<=p;i++)
          if(degree[i]==1)
               qe.push(i),degree[i]=0;
      bfs();
      for(int i=1;i<=p;i++)
      {
          if(degree[i]&&!vist[i])
          {
              sum=pond[i];
              num=1;
              dfs(i);
              if(num%2 == 1)
                  ans+=sum;
          }
      }
      printf("%lld\n",ans);
    }
    return 0;
}
