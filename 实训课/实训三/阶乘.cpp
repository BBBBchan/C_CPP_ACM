#include <stdio.h>
int main(){
	unsigned long long int n;
	scanf("%lld", &n);
	unsigned long long temp = n;
	unsigned long long answer = 1;
	for(int i = 0; i < n; i++){
		answer *= temp;
		temp--;
	}
	printf("%lld",answer);
	return 0;
}
