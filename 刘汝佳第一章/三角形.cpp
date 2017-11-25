#include <stdio.h>
int main()
{
	int a , b ,c ;
	scanf("%d%d%d",&a, &b, &c);
	if(((a + b) > c) && ((b + c) > a) && ((c + a) > b) ){
		a = a * a;
		b = b * b;
		c = c * c;
		if(((a + b) == c) || ((b + c) == a) || ((c + a) == b))
			printf("yes");
		else 
			printf("no");
		}
	else 
		printf("not a triangle");
	return 0 ;
}