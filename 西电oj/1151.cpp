#include <stdio.h>
int main(int argc, char const *argv[])
{
	long int a, b, c;
	while(scanf("%ld %ld %ld", &a, &b, &c) != EOF){
		if(a == 0 && b != 0)
			printf("1\n");
		else if(a==0 && b == 0 && c==0)
			printf("inf\n");
		else if(a == 0 && b == 0)
			printf("0\n");
		else if((b*b - 4*a*c) == 0 )
			printf("1\n");
		else if((b*b - 4*a*c) > 0)
			printf("2\n");
		else
			printf("0\n");
	} 
	return 0;
}