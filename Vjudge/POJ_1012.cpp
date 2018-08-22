#include <stdio.h>
int res[15];
void joseph(){
	for(int k = 1; k < 14; k++){
		int m;
		for(m = 1;; m++){
			int ans = 0,kase = 1;
			for(int i = 1; i <=k; i++){
				ans = (ans+m-1)%(2*k-i+1);
				if(ans < k){
					kase = 0;
					break;
				}
			}
			if(kase)
				break;
		}
		res[k] = m;
	}
}
int main(int argc, char const *argv[])
{	
	joseph();
	int k;
	while(scanf("%d", &k) != EOF && k){
		printf("%d\n", res[k]);
	}
	return 0;
}