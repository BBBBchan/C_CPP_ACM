#include <stdio.h>
#include <time.h>
int main()
{
	const int MOD = 1000000;
	int n , s = 0;
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; i++)
	{
		int fac = 1;
		for(int j = 1; j <= i; j++)
			fac = (fac * j % MOD);
		s = ((s + fac) % MOD);
	}
	printf("%d\n", s);
	printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC);
	return 0 ;
}
