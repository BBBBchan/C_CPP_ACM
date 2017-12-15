#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	unsigned int a, b ;
	printf("%d\n", sizeof(unsigned int));		//unsigned int 所占字节数 
	a = pow(2,32) - 1;
	b = a + 1;
	printf("a = %u\nb = %u",a, b);
	return 0;
}
