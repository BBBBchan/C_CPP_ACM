#include <stdio.h>
int SG(int x)
{
    if(x%4==0)return x-1;
    else if(x%4==3)return x+1;
    return x;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,n,ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            ans=ans^SG(a);
        }
        if(ans==0)
            printf("Bob\n");
        else 
            printf("Alice\n");
    }
    return 0;
}
