#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
long long int volume[1005], value[1005];
long long int dp[1005];
int main(int argc, char const *argv[])
{
	long long int n,v;
	while(scanf("%lld %lld", &n, &v) != EOF){
		memset(dp,0,sizeof(dp));
		memset(volume,0,sizeof(volume));
		memset(value,0,sizeof(value));
		for(int i = 1; i <= n; i++){
			scanf("%lld %lld", &volume[i], &value[i]);
		}
		for(long long int i=1; i<=n; i++)
        {
            for(long long int j=v; j>=volume[i]; j--)
            {
                if(dp[j]<dp[j-volume[i]]+value[i])
                {
                    dp[j]=dp[j-volume[i]]+value[i];
                }
            }
        }
        printf("%lld\n", dp[v]);
    }
	return 0;
}

