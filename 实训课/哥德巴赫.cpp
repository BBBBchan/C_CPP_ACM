#include <stdio.h>
#include <math.h>
int isprime(int n){
	for(int i = 2; i < sqrt(n); i++){
		if(n%i==0)
			return 0;
	}
	return 1;
}
int ans1, ans2;
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i <= n/2; i++){
		if(isprime(i) && isprime(n-i)){
			ans1 = i;
			ans2 = n-i;
		}
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}