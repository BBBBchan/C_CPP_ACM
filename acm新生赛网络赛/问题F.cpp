#include <stdio.h>
#include <string.h>
int main(){
	long long int t;
	while(scanf("%lld",&t) != EOF){
		int a[100];
		memset(a,0,sizeof(a));
		int i = 0;
		while(t > 0){
			a[i] = t%2;
			t /= 2;
			i++;
		}
		for(int n = 99; n >= 0;n--){
			if(a[n] == 1)
				printf("R");
			else printf("G");
		}
		printf("\n");
	}
	return 0;
}