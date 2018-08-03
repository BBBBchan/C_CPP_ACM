#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int a[n+1];
	a[1] = 1;
	for(int i = 2; i <= n; i++){
		if(i%2 == 1)
			a[i] = a[i-1];
		else if(i % 2 == 0)
			a[i] = (a[i-1]+a[i/2])%1000000007;
	}
	
	printf("%d\n", a[n]);
	
	return 0;
}