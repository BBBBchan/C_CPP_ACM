#include <stdio.h>
int main()
{
	int j ;
	int k ;
	int temp ;
	scanf("%d %d", &j , &k );
	temp = j ;
	j = k ;
	k = temp ;
	printf("%d %d ", j , k);
	return 0;
}