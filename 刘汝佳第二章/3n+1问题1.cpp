#include <stdio.h>
int main()
{
	int n1 , count ;
	scanf("%d", &n1);
	long long n = n1 ;
	count = 0 ;
	while(n != 1)
	{	count ++ ;
		switch(n % 2){
			case(0):
				n = n / 2 ;
				break ;
			case(1):
				n = 3 * n + 1 ;
				break ;
			}

	}	
	printf("%d", count );
	return 0 ;
}