/*
最长不下降子序列（LIS）
在一个数字序列中，找到一个最长的子序列（可以不连续），使得这个子序列是不下降（非递减)的。
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005], dp[100005];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int ans = -1;
	for(int i = 0; i < n; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(a[i] >= a[j] && dp[j]+1>dp[i]){
				dp[i] = dp[j]+1; 
			}
		}
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}