#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#define MAXN 300010
using namespace std;
int n,m;
struct point{
	int l,len,r;
}po[MAXN];
bool cmp(point i,point j)
  {
  	if(i.l!=j.r)return i.l<j.l;
  	else return i.r<j.r;
  }
int main()
  {
     int i,j,k;
     while(~scanf("%d%d",&n,&m))
     	{
     	   int ans=0;
     	   priority_queue<int,vector<int>,greater<int> >pq;
     	   memset(po,0,sizeof(po));
           for(i=1;i<=n;i++)
           	 {
           	 	scanf("%d%d",&po[i].l,&po[i].len);
           	 	po[i].r=po[i].l+po[i].len;
           	 }
           sort(po+1,po+n+1,cmp);
           for(i=1;i<=n;i++)
           	  {
           	     
           	  	 while(1)
           	  	 { 
           	  	 	if(pq.empty())
           	  	 	{
           	  	 		pq.push(po[i].r);
           	  	 		ans++;
           	  	 		break;
           	  	 	}
           	  	 	else if(pq.top()+m<po[i].l)
           	  	 		{
           	  	 		  pq.pop();
           	  	 		  continue;
           	  	 		}
           	  	 	else if(pq.top()>po[i].l)
           	  	 	{
           	  	 		pq.push(po[i].r);
           	  	 		ans++;
           	  	 		break;
           	  	 	}
           	  	 	else if(pq.top()<=po[i].l&&pq.top()+m>=po[i].l)
           	  	 	{
           	  	 		pq.pop();
           	  	 		pq.push(po[i].r);
           	  	 		break;
           	  	 	}
           	  	 }
           	  }
           	printf("%d\n",n-ans);
     	}
     return 0;
  }

