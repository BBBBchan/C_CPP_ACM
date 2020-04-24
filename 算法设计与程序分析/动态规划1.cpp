/*
最大连续子序列问题：
给定一个数字序列，求i,j使得A[i]+A[i+1]+...+A[j]最大，输出最大和
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005], dp[100005];
int main(int argc, char const *argv[])
{
	int n, ans = -1e9+7;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	dp[0] = a[0];
	for(int i = 1; i < n; i++){
		dp[i] = max(dp[i-1]+a[i], a[i]);
		if(dp[i] > ans){
			ans = dp[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}