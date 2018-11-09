#include <cstdio>
int main(int argc, char const *argv[]){
	long long int x,n,ans = 0;
	scanf("%lld %lld", &x, &n);
	for(int i = 0; i < n; i++){
		if(x <= 5){
			ans+=250;
		}
		x++;
		if(x>7)
			x-=7;
	}
	printf("%lld\n", ans);
	return 0;
}