#include<stdio.h>
int main()
{
    int t,k=0,x,n;
    scanf("%d",&t);
    while(++k<=t)
    {
        int ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&x);
            if(i%6==0||i%6==2||i%6==5)
                ans^=x;
        }
        if(ans)
            printf("Case %d: Alice\n",k);
        else
            printf("Case %d: Bob\n",k);
    }
    return 0;
}