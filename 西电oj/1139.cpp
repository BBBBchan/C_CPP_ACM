#include <stdio.h>
int F(long long int i){
	if(i == 0)
		return 0;
	if(i == 1)
		return 1;
	return F(i-1)+F(i-2);
}
int main(){
	long long int n;
	while(scanf("%lld", &n) != EOF){
		long long int i = 0;
		while(n>=0){
			i++;
			n -= F(i);
		}
		if((F(i)+n) > F(i-1))
			printf("%lld %lld\n", i, F(i)+n);
		else
			printf("%lld %lld\n", i-1, F(i-1));		
	}
	return 0;
}