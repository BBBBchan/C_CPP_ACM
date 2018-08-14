#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll ;
ll n,T,a;

struct cmp{
	bool operator ()(int &a,int &b){
		return a>b;
	}
};
priority_queue<int,vector<int>,cmp> q;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	while(!q.empty()) q.pop();
        scanf("%lld%lld",&n,&T);
        
        for(int i=n;i>=1;i--)
        {
            //scanf("%d",&a);
        	q.push(i);
		}
		
		int l=2,r=n;
		ll sum;
		int k;
		int mmin=INF;
		while(l<=r)
		{
			sum=0;
			k=(l+r)/2;
			int d=0;
			for(int i=1;i<=n;i++)
			{
				if((i!=1&&i%k==1)||i==n)
				{
					sum=2*sum+d;
					q.push(d);
					d=0;
				}
				d+=q.top();
				q.pop();	
			}
			if(sum>T)
			{
				l=k+1;
			}
			else
			{
				mmin=min(k,mmin);
				r=k-1;
			}	
		}        
        printf("%d\n",mmin);
	}
	return 0;
}



