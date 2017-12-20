#include <stdio.h>
#define maxn 100
int main(){
	int a[maxn] = {0};
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int x,kase = 0;
	scanf("%d", &x);
	for(int i = 0; i < n; i++){
		if(a[i] == x){
			kase++;
			printf("Case%d: %d\n", kase, i);
		}
	}
	if(kase == 0)
		printf("not found\n");
	return 0;
}