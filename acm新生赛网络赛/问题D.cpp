#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 1050
int x[maxn];
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		for(int i = 0; i < maxn; i++)
			x[i] = 0;
		int a, b ,c;
		scanf("%d %d %d", &a, &b, &c);
		int n, k;
		scanf("%d %d", &n, &k);
		x[a]++;
		int temp = a;
		for(int i = 1; i < n; i++){
			temp = (temp*b+c)%1001;
			x[temp]++;
		}
		int count = 0;
		// for(int i = 0; i < 10; i++)
		// 	printf("%d ", x[i]);
		for(int i = maxn; i >= 0; i--){
			if(x[i]!=0){
				count+=x[i];
				if(count >= k){
					printf("%d\n", i);
					break;
				}
			}
		}
	}
	return 0;
}