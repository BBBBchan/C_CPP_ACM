
LL qmod(LL a,LL b,LL c)//二进制的思想 
{
    LL res=1;
    while(b)
    {
        if(b&1) res=qmodx(res,a,c)%c;
        b>>=1;
        a=qmodx(a,a,c)%c;
    }
    return res;
}
LL qmodx(LL a,LL b,LL c)
{
    a%=c,b%=c;
    if(c<=1000000000) return a*b%c;
    return (a*b-(LL)(a/(long double)c*b+1e-8)*c+c)%c;//a*b%c=a*b-floor(a*b/mod)*mod 
}//O（1）快速乘取模问题 

LL C(LL n,LL m,LL p)//组合数模素数P
{
    if(m>n||m<0) return 0;
    if(n-m<m) m=n-m;
    LL a=1,b=1;
    for(int i=0; i<m; ++i)
    {
        a=a*(n-i)%p;
        b=b*(m-i)%p;
    }
    return a*qmod(b,p-2,p)%p;
}
LL Lucas(LL n,LL m,LL p)
{
    LL ans=1;
    while(n&&m&&ans)
    {
        ans=ans*C(n%p,m%p,p)%p;
        n/=p,m/=p;
    }
    return ans;
}