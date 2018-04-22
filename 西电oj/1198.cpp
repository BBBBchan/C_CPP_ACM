#include <stdio.h>
int main(){
	long long int n;
	while(scanf("%lld", &n) != EOF){
		if(n == 0)
			printf("1\n");
		else if(n == 1)
			printf("2\n");
		else{
			n = ((n)*(n-1) + 2) % 140105200078888888;
			printf("%lld\n", n);
		}
	}
	return 0;
}