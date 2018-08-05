#include <stdio.h>
#include <string.h>
#define maxn 431
int prime[maxn],vis[maxn]={0};
int a[440][440], b[440];
int len;

int primetable()         //打印素数表
{
    int i,j;
    int c=0;
    memset(vis,0,sizeof(vis));
    for(i=2;i<=431;i++)
    {
        if(!vis[i])
        {
            prime[c++]=i;
            for(j=i*i;j<=431;j+=i)
            {
                vis[j]=1;
            }
        }
    }
    return c;
}
void f(){
    int i,j;
    memset(a,0,sizeof(a));
    for(i=2;i<=431;i++)
    {
        int ii=i;
        memcpy(a[i],a[i-1],sizeof(a[i]));
        for(j=0;j<len;j++)
        {
            if(prime[j]>ii) break;
            if(ii%prime[j]==0)
            {
                int sum=0;
                while(ii%prime[j]==0)
                {
                    sum++;
                    ii/=prime[j];
                }
                a[i][prime[j]]+=sum;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
	len = primetable();
	f();
	int n, k;
	while(scanf("%d %d", &n, &k) != EOF){
		memcpy(b,a[n],sizeof(a[n]));
		long long int cnt = 1;
		for(int i = 0; i <= 431; i++){
			b[i] = b[i]-a[k][i]-a[n-k][i];
			cnt*=(1+b[i]);
		}
		printf("%I64d\n", cnt);
	}
	return 0;
}