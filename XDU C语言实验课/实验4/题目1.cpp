#include <stdio.h>
int isPrime(int x){
	for(int i = 2; i * i <= x; i++){
		if(x%i == 0){
			printf("%d is not a prime",x);
			return 0;
		}
	}
	printf("%d is a prime",x);
	return 1;
}
int main(){
	int x;
	scanf("%d",&x);
	isPrime(x);
	return 0;
}
