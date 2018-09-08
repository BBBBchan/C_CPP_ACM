#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e4+7,mod = 1e9+7;
int _cnt;
int pri[maxn];
bool tag[maxn];
int get_prime(){
    for(int i=2;i<maxn;i++){
        if(!tag[i]){
            pri[_cnt++]=i;
            for(int j=i;j<maxn;j+=i)
                tag[j]=1;
        }
    }
}
int fac[30],cnt;
int get_fac(int x){
    cnt=0;
    for(int i=0;pri[i]*pri[i]<=x&&i<_cnt;i++)
        if(x%pri[i]==0){
            fac[cnt++]=pri[i];
            while(x%pri[i]==0)
                x/=pri[i];
        }
    if(x>1)
        fac[cnt++]=x;
    return 0;

}
ll sum2(ll n){
    if((2*n+1)%3==0)
        return 1ll*((n*(n+1)/2)%mod)*((n*2+1)/3)%mod;
    return 1ll*((n*(n+1)/6)%mod)*((2*n+1))%mod;
}
ll sum1(ll n){
    return (1ll*n*(n+1)/2)%mod;
}
ll solve(ll m,ll n){
    int k,i,j;
    get_fac(m);
    ll ans =0;
    for(k=1;k<(1<<cnt);k++){
        ll tem = 1,flag =0;
        for(int i=0;i<cnt;i++){
            if(k&(1<<i))
                flag++,tem*=fac[i];
        }
        if(flag&1)
            ans = (ans+tem*tem*sum2(n/tem)+tem*sum1(n/tem))%mod;
        else
            ans =((ans-tem*tem*sum2(n/tem)-tem*sum1(n/tem))%mod+mod)%mod;
    }
    return ans;
}
int main(){
    get_prime();
    ll n,m;
    while(scanf("%lld%lld",&n,&m)!=EOF){
        ll ans = (sum2(n)+sum1(n))%mod;
        ll tem  = solve(m,n);
        ans = (ans-tem+mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}