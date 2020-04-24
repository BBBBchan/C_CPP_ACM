/*
01背包问题：
有n件物品，每件物品的重量为w[i]，价值为c[i]，现有一个容量为v的背包，问如何选取物品放入背包，使得背包内物品的总价值最大，其中每种物品都只有一件
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int w[10005], c[10005], dp[10005];
int main(int argc, char const *argv[])
{
	int n,v;
	scanf("%d %d", &n, &v);
	for(int i = 0; i <n; i++){
		scanf("%d", &w[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
	}
	//初始化滚动数组
	for(int i = 0; i <= v; i++){
		dp[v] = 0;
	}

	for(int i = 0; i <= n; i++){
		//逆序枚举每一个重量
		for(int j = v; j >= w[i]; j--){
			//状态转移方程
			dp[j] = max(dp[j], dp[j-w[i]]+c[i]);
		}
	}
	//滚动数组中最大值即为答案
	int ans = 0;
	for(int i = 0; i <= v; i++){
		if(dp[i] > ans){
			ans = dp[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}