#include <cstdio>
#include <algorithm>
using namespace std;
bool find(int *a, int left, int right, int key){
	if(left > right)
		return 0;
	int mid = left + (right-left)/2;
	if(a[mid] > key)
		return find(a,left,right-1,key);
	else if(a[mid] < key)
		return find(a,left+1,right,key);
	else
		return 1;
	return 0;
}
int main(int argc, char const *argv[])
{
	int a[100],b[100];
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	int n;
	scanf("%d", &n);
	for(int j = 0; j < n; j++){
		int kase=0;
		scanf("%d", &b[j]);
		for(int k = 0; k < m; k++){
			if(a[k] == b[j]){
				kase = 1;
				printf("Yes\n");
				continue;
			}
		}
		if(!kase)
			printf("No\n");
	}
	sort(a,a+m);
	for(int i = 0; i < n; i++){
		int left = 0, right = m-1,kase = 0;
		while(left <= right){
			int mid = left + (right-left)/2;
			if(a[mid] == b[i]){
				kase = 1;
				break;
			}
			else if(a[mid] > b[i]){
				right = mid-1;
				mid = (right+left)/2;
			}
			else if(a[mid] < b[i]){
				left = mid+1;
			}
		}
		if(kase)
			printf("Yes\n");
		else
			printf("No\n");
	}
	for(int i = 0; i < n; i++){
		if(find(a,0,m-1,b[i]))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
/*
5
23 1 15 11 10
6
23 1 11 10 15 4
*/
//二分查找，哈夫曼，排序，搜索，括号匹配