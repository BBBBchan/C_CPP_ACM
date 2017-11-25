#include <stdio.h>
int main ()
{
	int n , m ;
	while(scanf("%d %d", &n ,&m) == 2 && n < m && n != 0 )
	{
		double s = 0;
		for(int i = n ; i < m ;i++)
		{
			s += (double)(1 / (i * i));
		}
		printf("%.5f", s);
	}
	return 0 ;
}