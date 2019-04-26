#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int a[1005],b[1005];
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d", &n) != EOF){
		int count1 = 0, count2 = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			if(a[i] == 1000)
				count1++;
		}
		sort(a,a+n);
		for(int i = 0; i < n; i++){
			scanf("%d", &b[i]);
			if(b[i] == 1)
				count2++;
		}
		sort(b,b+n);
		int temp = 0;
		temp = min(count1,count2);
		int now = temp, ans = temp;
		for(int i = 0; i < n-temp; i++){
			for(int j = now; j < n; j++){
				if(a[i] == 1 && b[j] == 1000){
					break;
				}
				else if( a[i] < b[j]){
					ans++;
					now = j+1;
					break;
				}
			}
		}
		if(ans == 0)
			printf("wo qko mei you kai gua!\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}