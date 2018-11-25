#include <cstdio>
typedef long long LL;
LL qmodx(LL a,LL b,LL c)
{
    a%=c,b%=c;
    if(c<=1000000000) return a*b%c;
    return (a*b-(LL)(a/(long double)c*b+1e-8)*c+c)%c;//a*b%c=a*b-floor(a*b/mod)*mod 
}//O（1）快速乘取模问题 
LL qmod(LL a,LL b,LL c){
    LL res=1;
    while(b)
    {
        if(b&1) res=qmodx(res,a,c);
        b>>=1;
        a=qmodx(a,a,c);
    }
    return res;
}
int main(int argc, char const *argv[])
{
	long long int k;
	scanf("%lld", &k);
	printf("%lld\n", qmod(2,k-1,123456789));
	return 0;
}