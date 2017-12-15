#include <stdio.h>
int main()
{
	int m,n,p,q,t,times;
	scanf("%d %d",&m,&n);
	p = m;
	q = n;
	while(n != 0){
		t = n;
		n = m % n;
		m = t;	
	}
	times = p*q/m;
	printf("%d %d",m,times); 
	return 0;
}
