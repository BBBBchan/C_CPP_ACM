#include <stdio.h>
#include <math.h>
int main(){
	long long int g, l;
	while(scanf("%I64d %I64d", &g, &l) != EOF){
		long long int temp = l/g;
		for(int i = sqrt(temp*1.0); i > 1; i--){
			if(temp%i == 0){
				printf("%I64d %I64d\n", i*g, temp/i*g);
				break;
			}
		}
	}
	return 0;
}