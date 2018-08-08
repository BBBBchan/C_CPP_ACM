#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;
LL qmodx(LL a,LL b,LL c)
{
    a%=c,b%=c;
    if(c<=1000000000) return a*b%c;
    return (a*b-(LL)(a/(long double)c*b+1e-8)*c+c)%c;//a*b%c=a*b-floor(a*b/mod)*mod 
}//O（1）快速乘取模问题 

LL exgcd(LL a,LL b,LL &x,LL &y) //ax+by=d
{
    if(!b)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        LL r=exgcd(b,a%b,x,y);
        LL t = x;
        x = y;
        y=t-a/b*x;
        return r;
    }
}
LL CRT(LL a[],LL m[],LL len) //x%m[i]=a[i]
{
    LL i,x,y,M,n=1,ret=0;
    for(i=0; i<len; ++i) n*=m[i];
    for(i=0; i<len; ++i)
    {
        M=n/m[i];
        exgcd(M,m[i],x,y);//求逆元 
        ret=(ret+qmodx(qmodx(x,M,n),a[i],n))%n;
    }
    return (ret+n)%n;
}

int main(int argc, char const *argv[])
{   
    LL len = 3, a[3], b[3] = {23,28,33},d;
    int count = 0;
    while(scanf("%lld %lld %lld %lld", &a[0], &a[1], &a[2],&d) != EOF){
        if(a[0] == a[1] && a[1] == a[2] && a[2]==d && d == -1)
            break;
        a[0]%=23;
        a[1]%=28;
        a[2]%=33;
        count++;
        LL ans = CRT(a,b,len) - d;
        if(ans<=0)
            ans+=21252;
        printf("Case %d: the next triple peak occurs in %lld days.\n", count, ans);
    }
    return 0;
}