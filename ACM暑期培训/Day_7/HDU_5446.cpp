#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =1e5+5;
ll n, m, p, fac[N],inv[N], P[15],Q[15];
ll powmod(ll a,ll b,ll mod){
    ll ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
ll mul(ll a,ll b,ll mod){
    a=(a%mod+mod)%mod;
    b=(b%mod+mod)%mod;
    ll ans=0;
    while(b){
        if(b&1) ans+=a,ans=(ans>=mod?ans-mod:ans);
        b>>=1; a<<=1;
        a=(a>=mod?a-mod:a);
    }
    return ans;
}
void ex_gcd(ll a,ll b,ll gcd,ll& x,ll& y){
    if(!b) x=1,y=0,gcd=a;
    else ex_gcd(b,a%b,gcd,y,x),y-=x*(a/b);
}
void init(int n){
    fac[0]=1;
    for(int i=1;i<n;i++) fac[i]=fac[i-1]*i%n;
    inv[n-1]=powmod(fac[n-1],n-2,n);
    for(int i=n-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%n;
}

ll Lucas(ll n,ll m,ll mod){
    ll ans=1;
    while(n&&m){
        ll a=n%mod,b=m%mod;
        if(a<b) return 0;
        ans=ans*fac[a]%mod*inv[b]%mod*inv[a-b]%mod;
        n/=mod,m/=mod;
    }
    return ans;
}
ll china(ll n,ll* a,ll* m){
    ll M=1,w,gcd,x,y,ans=0;
    for(int i=0;i<n;i++) M*=m[i];
    for(int i=0;i<n;i++){
        w=M/m[i];
        ex_gcd(m[i],w,gcd,x,y);
        ans=(ans+mul(mul(y,w,M),a[i],M)+M)%M;
    }
    return ans;
}

int main()
{
    int t;
    ll k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld%lld%lld", &n, &m, &k);
        for(int i = 0; i < k; i++){
            scanf("%lld",&P[i]);
            p = P[i];
            init(p);
            Q[i] = Lucas(n,m,p);
        }
        ll ans = china(k,Q,P);
        printf("%lld\n", ans);
    }

    return 0;
}
