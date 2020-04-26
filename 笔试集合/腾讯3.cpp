/*Lucas定理，用于组合数取模，使用方法Lucas(n,m,p)，求C(n,m)%p*/
#include <cstdio>

long long qmodx(long long a,long long b,long long c)
{
    a%=c,b%=c;
    if(c<=1000000000) return a*b%c;
    return (a*b-(long long)(a/(long double)c*b+1e-8)*c+c)%c;//a*b%c=a*b-floor(a*b/mod)*mod 
}//O（1）快速乘取模问题 
long long qmod(long long a,long long b,long long c)//二进制的思想 
{
    long long res=1;
    while(b)
    {
        if(b&1) res=qmodx(res,a,c)%c;
        b>>=1;
        a=qmodx(a,a,c)%c;
    }
    return res;
}
long long C(long long n,long long m,long long p)//组合数模素数P
{
    if(m>n||m<0) return 0;
    if(n-m<m) m=n-m;
    long long a=1,b=1;
    for(int i=0; i<m; ++i)
    {
        a=a*(n-i)%p;
        b=b*(m-i)%p;
    }
    return a*qmod(b,p-2,p)%p;
}
long long Lucas(long long n,long long m,long long p)
{
    long long ans=1;
    while(n&&m&&ans)
    {
        ans=ans*C(n%p,m%p,p)%p;
        n/=p,m/=p;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d%d", &n, &m);
    if(m > n){
        printf("%lld\n", Lucas(m,n,1000003));
    }
    return 0;
}