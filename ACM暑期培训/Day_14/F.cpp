#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int a[100500];
int degree[100500];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        memset(degree,0,sizeof(degree));
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        if(m==0)
        {
            printf("Impossible\n");
        }
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            degree[x]++;
            degree[y]++;
        }
        int ji=0;
        for(int i=1;i<=n;i++)
        {
            if(degree[i]%2==1)ji++;
        }
        if(ji==0||ji==2)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                if(((degree[i]+1)/2)%2==1)
                {
                    ans^=a[i];
                }
            }
            if(ji==0)
            {
                for(int i=1; i<=n; i++)
                {
                    ans=max(ans, ans^a[i]);
                }
            }
            printf("%d\n",ans);
        }
        else printf("Impossible\n");
    }
}
