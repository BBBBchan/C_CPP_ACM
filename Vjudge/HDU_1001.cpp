#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d", &n)!=EOF){
		long long int ans =0;
		for(int i = 0; i <= n; i++)
			ans+=i;
		printf("%lld\n", ans);
		printf("\n");
	}
	return 0;
}