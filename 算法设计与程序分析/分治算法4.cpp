/*
给定长度为n的数组a和数组b，求解有多少对数据满足ai+aj > bi+bj (i>j)
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long a[200005], b[200005],c[200005],ans=0;
//二分上界搜索，在容器a中查找元素val的上界
long long binarySearchUpperBound(long long a[], long long n, long long val) {
    if (val > a[n-1]) return -1;
    if (val < a[0])	  return 0;
    int begin = 0, end = n - 1, mid;
    while (begin < end) {
        mid = (begin + end) / 2 + 1;
        if (a[mid] > val)
            end = mid - 1;
        else
            begin = mid;
    }
    return begin + 1;
}

int main(int argc, char const *argv[])
{
	long long n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
		c[i] = a[i]-b[i];
	}
	//转换数据形式，在数组c中存储a[i]-b[i]并进行排序
	sort(c, c+n);
	//寻找b[j]-a[j]
	for(int i = 0; i < n; i++){
		// long long k = std::upper_bound(c, c+n, -c[i]) - c;
		long long k = binarySearchUpperBound(c, n, -c[i]);
		if(c[i] > 0){
			ans--;
		}
		// 每次查找统计符合条件的数量
		ans+=(long long)n-k;
	}
	printf("%lld\n", ans/2);
	return 0;
}