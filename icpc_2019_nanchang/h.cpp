#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define N 3
#define mo 998244353
#define LL long long
using namespace std;
LL f[N],g[N],h[N],s1[N],a[N],u1[N];
long long  n,m;
void mul(LL *x,LL *y,LL *z)
{
    for(long long i= 0;i <= 2;i++) u1[i]=0;
    for(long long i = 0; i <= 1;i++) 
        for(long long j = 0;j <=1;j++) 
            u1[i+j]=(u1[i+j]+x[i]*y[j])%mo;
    for(long long j=0;j<=2;j++) 
        u1[j]=(u1[j]-f[j]*u1[2])%mo; 
    for(long long i= 0;i <= 1;i++) z[i]=u1[i];
}
int main()
{
    LL  q;
    scanf("%lld %lld", &q, &n);
    m = 2;
    a[1] = 3;
    f[1] = -3;
    a[2] = 2;
    f[0] = -2;
    f[m]=1;
    g[1]=1;
    s1[0]=1;
    for(long long t=n;t;t>>=1LL){
        if(t&1) mul(s1,g,s1);
        mul(g,g,g);
    }
    h[0] = 0;
    h[1] = 1;
    LL ans=0, fin;
    for(long long i= 0;i <= 1;i++)
        ans=(ans+s1[i]*h[i]%mo+mo)%mo;
    fin = ans;
    //q--;
 //   printf("%lld\n", ans);
    int cnt =0;
    
    for(int j = 1; j < q; j++){
        cnt++;
        n^=(ans*ans);
        int aans = ans;
         memset(g,0,sizeof(a));
         memset(s1,0,sizeof(a));
    g[1]=1;
    s1[0]=1;
    for(long long t=n;t;t>>=1LL)
    {
        if(t&1) mul(s1,g,s1);
        mul(g,g,g);
    }
    h[0] = 0;
    h[1] = 1;
    ans = 0;
    for(long long i= 0;i <=1;i++) 
        ans=(ans+s1[i]*h[i]%mo+mo)%mo;
  // printf("%lld\n",ans);
   //long long ffin = fin;
   //printf("%lld\n", cnt); 
        fin ^= ans;
        if(ans == aans){
           // printf("%lld %d\n", ans, cnt);
            break;
    }

    }
    if(q > cnt+1){
        if((q-cnt-1)%2 == 1){
          //  printf("sadasdas\n");
            printf("%lld", fin^ans);
        }
        else{
         //   printf("+1s\n");
            printf("%lld", fin);
        }
    }
    else{
        printf("%lld", fin);
    }
    return 0;
    
}
//75811 473844410