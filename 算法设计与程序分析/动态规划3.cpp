/*
给出一个字符串s，求s的最长回文子串长度
*/
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
//dp[i][j]表示a[i]到a[j]所表示的子串是否是回文子串
int dp[10005][10005];
int main(int argc, char const *argv[])
{
	string a;
	cin >> a;
	int ans = 1;//记录最长回文子串长度
	//初始化边界条件
	for(int i = 0; i < a.size(); i++){
		dp[i][i] = 1;
		if(i < a.size()-1){
			if(a[i] == a[i+1]){
				dp[i][i+1] = 1;
				ans = 2;
			}
		}
	}
	// 枚举子串长度
	for(int l = 3; l <= a.size(); l++){
		// 枚举左端点
		for(int i = 0; i+l-1 < a.size(); i++){
			int j = i + l - 1;
			if(a[i] == a[j] && dp[i+1][j-1] == 1){
				dp[i][j] = 1;
				ans = l;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}