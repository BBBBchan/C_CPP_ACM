#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int a[65],vis[65];
int cmp(int a, int b){
	return a>b;
}
int dfs(int pos, int sum, int clen, int cstick, int finstick){
	if(cstick == finstick)
		return 1;
	if(sum == clen)
		return dfs(0,0,clen,cstick+1,finstick);
	for(int i = pos,pre=0; i < n; i++){
		if(vis[i]||sum+a[i]>clen||pre==a[i])
			continue;
		pre = a[i];
		vis[i] = 1;
		if(dfs(i+1,sum+a[i],clen,cstick,finstick))
			return 1;
		vis[i] = 0;
		if(pos == 0)
			return 0;
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	while(scanf("%d", &n) && n){
		int sum=0,max=0;
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			sum+=a[i];
		}
		sort(a,a+n,cmp);
		for(int i = n; i > 0; i--){
			memset(vis,0,sizeof(vis));
			if(sum%i==0 && dfs(0,0,sum/i,0,i)){
				printf("%d\n", sum/i);
				break;
			}
		}
	}
	return 0;
}