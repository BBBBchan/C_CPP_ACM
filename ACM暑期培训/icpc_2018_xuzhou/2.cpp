#include <cstdio>
#include <map>
#include <iostream>
#define N 20000000
using namespace std;
long long a,b,n,num;
int mu[N+10],pri[1300010],top;
bool mark[N+10];
map<long long,long long>V;
int miu(int n) {
    for(int i=2; i*i<=n; i++) {
        if(n%i==0) {
            num++;
            int cnt=0;
            while(n%i==0) {
                n/=i;
                cnt++;
            }
            if(cnt>1)
                return 0;
        }
    }
    return (num&1)?1:-1;
}
void shake()
{
    mu[1]=1;
    for(int i=2;i<=N;i++)
    {
        if(!mark[i])
        {
            pri[++top]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=top && i*pri[j]<=N;j++)
        {
            mark[i*pri[j]]=true;
            if(i%pri[j]==0) break;
            mu[i*pri[j]]=-mu[i];
        }
    }
    for(int i=2;i<=N;i++) mu[i]+=mu[i-1];
}
long long calc(long long x)
{
    if(x<=N) return mu[x];
    if(V[x]) return V[x];
    long long ans=1;
    for(long long i=2,r;i<=x;i=r+1)
    {
        r=x/(x/i);
        ans-=calc(x/i)*(r-i+1);
    }
    V[x]=ans;
    return ans;
}
int main(){
    shake();
    cin>>a>>b;
    cout<<calc(b0)-calc(a-1)<<endl;
    return 0;
}