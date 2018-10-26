#include<bits/stdc++.h>
using namespace std;
int W,ans=0;
int n,a[30001];
int l,r,i;
int main()
{
    scanf("%d%d",&W,&n);
    for(i=1;i<=n;i++)
      scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    l=1;  r=n;
    while(l<=r)//一定要有等号。
    {
        if(a[l]+a[r]<=W)   //一定要有等号。
          l++,r--,ans++;
        else
          r--,ans++;   //贪心过程
    }
    printf("%d",ans);
    return 0;
}
