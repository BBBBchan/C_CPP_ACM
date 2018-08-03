#include <stdio.h>
long long int SG(long long int p){
	if(p == 1)
		return 0;
	else if(p%2==0)
		return (p/2);
	return SG(p/2);
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		long long int ans = 0;
		scanf("%d", &n);
		long long int a;
		for(int i = 0; i < n; i++){
			scanf("%lld", &a);
			ans = ans^SG(a);
		}
		if(ans == 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}