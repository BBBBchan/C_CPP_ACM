#include <stdio.h>
#define maxn 3000010
// ll Euler(int a){
// 	ll ans = a;
// 	for(int i = 2; i*i<=a; i++){
// 		if(a%i == 0){
// 			ans = (ans/i)*(i-1);
// 			while(a%i == 0)
// 				a/=i;
// 		}
// 	}
// 	if(a>1)
// 		ans = (ans/a)*(a-1);
// 	return ans;
// }
long long int Euler[maxn];
void euler(){
	for(int i = 1; i < maxn; i++)
		Euler[i] = i;
	for(int i = 2; i < maxn; i++){
		if(Euler[i] == i){
			for(int j = i; j < maxn; j+=i){
				Euler[j] = (Euler[j]/i)*(i-1);
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int a, b;
	euler();
	while(scanf("%d %d", &a, &b) != EOF){
		long long int ans = 0;
		for(int i = a; i <= b; i++){
			ans += Euler[i];
		}
		printf("%I64d\n", ans);
	}
	return 0;
}