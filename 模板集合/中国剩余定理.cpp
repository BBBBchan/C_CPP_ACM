/*中国剩余定理，求同余方程使用，使用方法F(a,m,len)，a存储原方程结果，m存原方程模数，len表示方程个数
  返回结果x为同余方程的一组解*/
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
