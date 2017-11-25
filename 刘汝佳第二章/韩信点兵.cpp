#include <stdio.h>
int main()
{
	int a , b , c ,kase = 0;
	while(scanf("%d %d %d", &a, &b, &c) == 3)
	{
		int m = kase;
		for(int n = 10 ; n <= 100 ; n++)
		{	
			if((n % 3 == a) && (n % 5 == b) && (n % 7 == c)) 
				{
					printf("Case %d: %d\n",++kase ,n);
					continue;
				}
		
		}
		if(m == kase) printf("Case %d: No answer\n",++kase);
	}
	return 0 ;
}
