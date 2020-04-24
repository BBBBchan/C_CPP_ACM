/*
输入包含n个整数是数组A和整数x，求出满足A[i] + A[j] = x的i和j，如果没有这样的元素和，则返回-1和-1.
*/
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int num;
	int index;
}a[1000];
bool cmp(node a, node b){
	return a.num < b.num;
}
int main(int argc, char const *argv[]){
	int n, x;
	scanf("%d %d", &n, &x);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i].num);
		a[i].index = i;
	}
	// 将Nodes中的值从小到大排序
	sort(a,a+n,cmp);
	int ansl = -1, ansr = -1, kase = 0;
	//枚举左端点，二分右端点
	for(int i = 0; i < n; i++){
		int left = i+1, right = n-1;
		if(kase){break;}
		while(right >= left){
			int mid = left + (right-left)/2;
			if(a[i].num + a[mid].num > x){
				right = mid-1;
			}
			else if(a[i].num + a[mid].num < x){
				left = mid+1;
			}
			else{
				ansl = a[i].index;
				ansr = a[mid].index;
				kase = 1;
				break;
			}
		}
	}
	printf("%d %d\n", ansl, ansr);
	return 0;
}