#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#define MAXN 100010
int	n_PrimeCnt;
int	n_Prime[30];
int	n_Mark[70];
int cnt=0,cnt2=0;
map<long long,int>ma;
long long	n_Multi[30];
using namespace std;
int n,m,src,end;
vector<pair<int,int> >g[MAXN+10];
long long dis[MAXN+10];
bool inque[MAXN+10];
queue<int>que;
void spfa(){
	memset(dis,63,sizeof(dis));
	dis[src]=0;
	while(!que.empty())que.pop();
	que.push(src);
	inque[src]=1;
	while(!que.empty()){
		int u=que.front();
		que.pop();
		for(int i=0;i<g[u].size(),i++)
			if(dis[u]+g[u][i].second<dis[g[u][i].first]){
				dis[g[u][i].first]=dis[u]+g[u][i].second;
				if(!inque[g[u][i].first]){
					inque[g[u][i].first]=1;
					que.push(g[u][i].first);
				}
			}
		inque[u]=0;
	}
}
void v_Prime()
{
	for (int i = 2; i < 70; i++)
	{
		if (n_Mark[i])
		{
			n_PrimeCnt++;
			n_Prime[n_PrimeCnt]	= i;
		}

		for (int j = 1; j <= n_PrimeCnt; j++)
		{
			if (i * n_Prime[j] > 70)
			{
				break;
			}

			n_Mark[i * n_Prime[j]]	= 0;

			if (i % n_Prime[j] == 0)
			{
				break;
			}
		}
	}

	n_Multi[1]	= n_Prime[1];

	for (int i = 2; i < n_PrimeCnt; i++)
	{
		printf ("%d\n", n_Prime[i]);
		n_Multi[i]	= n_Multi[i - 1] * n_Prime[i];

		if (n_Multi[i] > 1e18)
		{
			break;
		}
	}
}
long long gold(long long x)
{
	int pos=lower_bound(n_Multi+1,n_Multi+17,x)-n_Multi;
	return pos-1;
}

int main()
{
	for (int i = 2; i < 70; i++)
	{
		n_Mark[i]	= 1;
	}
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
    	long long tmp;
    	cnt++;
    	scanf("%lld",&tmp);
    	src=min(src,tmp);
    	end=max(end,tmp);
        ma[tmp]=cnt;
    }
    src=ma[src];
    end=ma[end];
	v_Prime();
	for(i=1;i<=m;i++)
	{
		long long aa,bb,cc;
		scanf("%lld%lld%lld",&aa,&bb,&cc);
		aa=ma[aa];
		bb=ma[bb];
		cnt2++;
		pair<int,int>p;
		p.first=cnt2;
		p.second=cc;
		g[aa].push_back(p);
		p.first=++cnt2;
		g[bb].push_back(p);
	}
    long long xx;
    scanf("%lld",&xx);
    printf("%lld",gold(xx));
	return 0;
}