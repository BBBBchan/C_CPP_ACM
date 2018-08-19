#include <stdio.h>
int main(int argc, char const *argv[])
{
	long long int n,q,x,y,ans;
	scanf("%lld %lld", &n, &q);
	for(int i = 0; i < q; i++){
		scanf("%lld %lld", &x, &y);
		if(x%2==y%2){
			if(n%2==0)
				ans = (n/2)*(x-1) + (y+1)/2;
			else if(x%2==1){
				ans = n*((x-1)/2) + (y+1)/2;
			}
			else if(x%2==0){
				ans = n*(x-2)/2 + (n+1)/2 + (y+1)/2;
			}
		}
		else{
			if(n%2==0)
				ans = (n/2)*(x-1) + (y+1)/2 + (n*n+1)/2;
			else if(x%2==1){
				ans = n*((x-1)/2) + (y+1)/2 + (n*n+1)/2;
			}
			else if(x%2==0){
				ans = n*(x-1)/2+ (y+1)/2 + (n*n+1)/2;
			}			
		}
		printf("%lld\n", ans);
	}
	return 0;
}