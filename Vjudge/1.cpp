#include <stdio.h>
int k;
int joseph(int n, int m){
	int ans = 0;
	for(int i = 1; i <=k; i++){
		ans = (ans+m-1)%(n-i+1);
		if(ans+1 <= k)
			return 0;
	}
	return ans+1;
}
int main(int argc, char const *argv[])
{
	while(scanf("%d", &k) != EOF){
		int m;
		for(int m = 1;; m++){
			if(joseph(2*k,m)){
				printf("%d\n", m);
				break;
			}
		}
	}
	return 0;
}
