#include <cstdio>
typedef long long LL;
LL qmodx(LL a,LL b,LL c)
{
    a%=c,b%=c;
    if(c<=1000000000) return a*b%c;
    return (a*b-(LL)(a/(long double)c*b+1e-8)*c+c)%c;//a*b%c=a*b-floor(a*b/mod)*mod 
}//O（1）快速乘取模问题 

LL qmod(LL a,LL b,LL c)//二进制的思想 
{
    LL res=1;
    while(b)
    {
        if(b&1) res=qmodx(res,a,c)%c;
        b>>=1;
        a=qmodx(a,a,c)%c;
    }
    return res%c;
}

int main(int argc, char const *argv[])
{
    LL a, b, c, ans;
    scanf("%lld %lld %lld", &a, &b, &c);
    ans = qmod(a,b,c);
    printf("%lld^%lld mod %lld=%lld\n", a, b, c, ans);
    return 0;
}