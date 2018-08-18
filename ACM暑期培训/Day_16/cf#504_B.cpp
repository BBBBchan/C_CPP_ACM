#include <stdio.h>
int main(int argc, char const *argv[])
{
	long long int n,k;
	while(scanf("%lld %lld", &n, &k)!=EOF){
		if(k <= n)
			printf("%lld\n", (k-1)/2);
		else if(k%2==1&&n>=(k+1)/2)
			printf("%lld\n", n-((k+1)/2)+1);
		else if(k%2==0&&n>(k+1)/2)
			printf("%lld\n", (n-(k+1)/2));
		else
			printf("0\n");
	}
	return 0;
}