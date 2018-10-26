#include <cstdio>
#include <algorithm>
using namespace std;
int a[20009];
bool cmp(int a, int b){
	return a>b;
}
int main()
{
	int n;
	scanf("%d", &n);
	int temp = n;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a,a+n,cmp);
	int ans = 0;
	for(int i = 0; i < temp-1; i++){
		a[n-2] = a[n-1]+a[n-2];
		ans+=a[n-2];
		int temp1 = n-3, temp2 = n-2;
		while(temp1>=0 && a[temp1] < a[temp2]){
			swap(a[temp1], a[temp2]);
			temp1--;
			temp2--;
		}	
		n--;
	}
	printf("%d", ans);
	return 0;
}