#include <stdio.h>
#include <time.h>
int main ()
{
	int n , m ;
	while(scanf("%d %d", &n ,&m) == 2 && n < m && n != 0 )
	{
		double s = 0;
		for(int i = n ; i <= m ;i++)
		{
			s += ((double)1.0 / (i * i));
		}
		printf("%.5f", s);
	}
	printf("Time used = %.2f\n",(double)clock() / CLOCKS_PER_SEC);
	return 0 ;
}