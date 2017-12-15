#include <stdio.h>
int main(){
	int a1, a2, b1, b2, a3, b3;
	scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
	a3 = a1 + a2;
	b3 = b1 + b2;
	printf("%d+%di",a3,b3);
	return 0;
}
