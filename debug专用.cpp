#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#define MAXN 1010000
#define LL long long
#define ll __int64
#define INF 0x7fffffff
#define mem(x) memset(x,0,sizeof(x))
#define PI acos(-1)
#define eps 1e-8
using namespace std;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll powmod(ll a,ll b,ll MOD){ll ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}
double dpow(double a,ll b){double ans=1.0;while(b){if(b%2)ans=ans*a;a=a*a;b/=2;}return ans;}
//head
ll eular(ll n)
{
    ll ret=1,i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            n/=i,ret*=i-1;
            while(n%i==0)
            n/=i,ret*=i;
        }
    }
    if(n>1)
    ret*=n-1;
    return ret;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        ll ans=0;
        for(int i=1;i<=(int)sqrt(n*1.0);i++)
        {
            if(n%i==0)
            {
                ans+=n/i*eular(i);
                if(i*i!=n)
                ans+=i*eular(n/i);
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

