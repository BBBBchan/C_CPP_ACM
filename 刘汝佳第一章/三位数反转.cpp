#include <stdio.h>
int main()
{
	int num, m;
	scanf("%d",&num);
	m = (num%10) * 100 + (num/10%10)*10 + (num/100);
	printf("%03d\n",m);
	return 0;
}