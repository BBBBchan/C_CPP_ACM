#include <stdio.h>
#define LOCAL
#define INF 1000000000
int main()
{
	#ifdef LOCAL
		freopen("data.in", "r", stdin);
		freopen("data.out", "w", stdin);
	#endif
	int x, n = 0, kase = 0;
	while(scanf("%d", &n) == 1 && n)
	{
		int s = 0 , min = INF , max = -INF;
		for(int i = 0 ;i < n; i++){
			scanf("%d", &x);
			s += x ;
			if(x > max) max = x ;
			if(x < min) min = x ;
		}
		if(kase) printf("\n");
		printf("Case %d: %d %d %.3f", ++kase, min, max, (double)s / n);
	}
	return 0 ;
}
