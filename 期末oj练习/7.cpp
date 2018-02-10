#include <stdio.h>
int main(){
	int n;
	while(scanf("%d", &n) && n != 0){
	int sum;
		while(n != 0){
			sum =0;
			while(n != 0){
				sum += (n % 10);
				n /= 10;
			}
			if(sum > 9)
				n = sum;
		}
		printf("%d\n", sum);
	}
	return 0;
}