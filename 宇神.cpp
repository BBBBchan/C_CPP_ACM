#include <stdio.h>
int main()
{
	int n ;
	scanf("%d", &n);
	while(n < 666)
	{
		printf("you lose");
		scanf("%d",&n);
	}
	while(n > 666)
	{
		printf("you lose!!!!!!!");
		scanf("%d", &n);
	}
	printf("you win!");
	return 0;
}