#include <stdio.h>
#include <math.h>
#include <algorithm>
int main(int argc, char const *argv[])
{
	int n,h,a,b,k,t1,f1,t2,f2,ans = 0;
	scanf("%d %d %d %d %d", &n, &h, &a, &b, &k);
	for(int i = 0; i < k; i++){
		scanf("%d %d %d %d", &t1, &f1, &t2, &f2);
		ans = abs(t1-t2);
		if(t1 == t2){
			ans += abs(f1-f2);
		}
		else if(f2 > b){
			ans= ans+abs(f1-b)+(f2-b);
		}
		else if(f2 < a){
			ans = ans + abs(f1-a)+(a-f2);
		}
		else{
			ans += abs(f1 - f2);
		}
		printf("%d\n", ans);
	}
	return 0;
}