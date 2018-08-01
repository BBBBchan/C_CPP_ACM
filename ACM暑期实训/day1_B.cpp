#include <stdio.h>
long long int gcd(long long int a,long long int b)
{
    return b==0?a:gcd(b,a%b);
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	long long int count[1000] = {0};
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++){
		int temp = a[i];
		do{
			temp = a[temp-1];
			count[i]++;
		}while(temp!=a[i]);
	}
	long long int ans = count[0];
	for(int i = 1; i < n; i++)
		ans = ans*count[i]/gcd(ans,count[i]);
	printf("%I64d\n", ans);
	return 0;
}