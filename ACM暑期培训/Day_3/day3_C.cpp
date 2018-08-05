#include <stdio.h>
#include <math.h>
long long int n,i;
long long int Euler(int a){
	int ans = a;
	for(int i = 2; i<=sqrt(a); i++){
		if(a%i == 0){
			ans = (ans/i)*(i-1);
			while(a%i == 0)
				a/=i;
		}
	}
	if(a>1)
		ans = (ans/a)*(a-1);
	return ans;
}
int main(int argc, char const *argv[])
{
	long long int ans;
	while(scanf("%I64d", &n) != EOF){
		ans=0;
		int temp = sqrt(n);
		for(i = 1; i <= temp; i++){
			if(n%i == 0){
				ans +=n/i*Euler(i);
				if(i*i != n)
					ans+=i*Euler(n/i);
			}
		}
		printf("%I64d\n", ans);
	}
	return 0;
}