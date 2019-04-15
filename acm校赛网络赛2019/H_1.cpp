#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 5000003
#define LL long long
#define p 1004535809
using namespace std;
int n,m;
int a[N],b[N],c[N],jc[N],inv_j[N],wn[N];
LL quickpow(LL num,LL x)
{
    LL base=num%p; LL ans=1;
    while (x) {
        if (x&1) ans=ans*base%p;
        x>>=1;
        base=base*base%p;
    }
    return ans;
}
void init()
{
    jc[0]=1; inv_j[0]=quickpow(jc[0],p-2);
    for (int i=1;i<=n;i++) 
     jc[i]=(LL)jc[i-1]*i%p,inv_j[i]=quickpow(jc[i],p-2);
    for (int i=1;i<=n*8;i<<=1)
     wn[i]=quickpow(3,(p-1)/(i<<1));
}
void NTT(int n,int *a,int opt)
{
    for (int i=0,j=0;i<n;i++) {
        if (i>j) swap(a[i],a[j]);
        for (int l=n>>1;(j^=l)<l;l>>=1);
    }
    for (int i=1;i<n;i<<=1) {
        LL wn1=wn[i]; 
        for (int p1=i<<1,j=0;j<n;j+=p1) {
            LL w=1;
            for (int k=0;k<i;k++,w=(LL)w*wn1%p) {
                int x=a[j+k]; int y=(LL)a[j+k+i]*w%p;
                a[j+k]=(x+y)%p; a[j+k+i]=(x-y+p)%p;
            }
        }
    }
    if (opt==-1) reverse(a+1,a+n);
}
void inverse(int n,int *a,int *b,int *c)
{
    if (n==1) b[0]=quickpow(a[0],p-2);
    else {
        inverse((n+1)>>1,a,b,c);
        int k=0;
        for (k=1;k<=(n<<1);k<<=1);
        for (int i=0;i<n;i++) c[i]=a[i];
        for (int i=n;i<k;i++) c[i]=0;
        NTT(k,c,1);
        NTT(k,b,1);
        for (int i=0;i<k;i++) {
            b[i]=(LL)(2-(LL)c[i]*b[i]%p)*b[i]%p;
            if (b[i]<0) b[i]+=p;
        }
        NTT(k,b,-1);
        int inv=quickpow(k,p-2);
        for (int i=0;i<k;i++) b[i]=(LL)b[i]*inv%p;
        for (int i=n;i<k;i++) b[i]=0;
    }
}
int main()
{

    scanf("%d",&n); init();
    int n1=0; 
    for (n1=1;n1<=n*2;n1<<=1);
    a[0]=1;
    for (int i=1;i<=n;i++) a[i]=(LL)quickpow(2,(LL)i*(i-1)/2)*inv_j[i]%p;
    inverse(n1,a,b,c);
    memset(c,0,sizeof(c)); 
    for (int i=1;i<=n;i++) c[i]=(LL)quickpow(2,(LL)i*(i-1)/2)*inv_j[i-1]%p;
    NTT(n1,b,1); NTT(n1,c,1);
    for (int i=0;i<=n1;i++) b[i]=(LL)b[i]*c[i]%p;
    NTT(n1,b,-1);
    LL inv=quickpow(n1,p-2);
    for (int i=0;i<=n1;i++) b[i]=(LL)b[i]*inv%p;
    printf("%d\n",(LL)b[n]*jc[n-1]%p);
}