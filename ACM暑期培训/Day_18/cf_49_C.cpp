#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int vis[10005], val[10005];
int main(int argc, char const *argv[])
{
	int t,n;
	scanf("%d", &t);
	while(t--){
		int k = 0, kase = 1,temp;
		scanf("%d", &n);
		memset(vis,0,sizeof(vis));
		for(int i = 1; i <= n; i++){
			scanf("%d", &temp);
			vis[temp]++;
			if(vis[temp] == 2 && kase)
				val[++k] = temp;
			if(vis[temp] == 4 && kase){
				printf("%d %d %d %d\n", temp, temp, temp, temp);
				kase = 0;
			}
		}
		if(kase){
			int idx = 1;
			sort(val+1, val+k+1);
			for(int i = 2; i < k; i++){
				if(val[idx] * val[i+1] < val[idx+1]*val[i])
					idx = i;
			}
			printf("%d %d %d %d\n", val[idx], val[idx], val[idx+1], val[idx+1]);
		}
	}
	return 0;
}