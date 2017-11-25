#include <stdio.h>
#include <math.h>
int main()
{	
	int a , b , c ;
	for(int n = 100; n <= 999; n++){
	
	a = n % 10 ;
	b = (n / 10) %10 ;
	c = (n / 100);
	a = pow((double)a,3);
	b = pow((double)b,3);
	c = pow((double)c,3);
	if(a + b + c == n)
		printf("%d ",n);
	}
	return 0 ;
}
