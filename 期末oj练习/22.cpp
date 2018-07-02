#include <stdio.h>
int main(){
	long long int n;
	while(scanf("%lld",&n) && n != 0){
	int sum = 0;
		while(n!=0){
			sum = 0;
			while(n!=0){
				sum+=(n%10);
				n/=10;
			}
			if(sum >= 10)
				n = sum;
		}
	printf("%d\n",sum);
	}
	return 0;
}
