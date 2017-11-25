#include <stdio.h>
int main(){
	int a,b,c,d,sum1;
	float aver1,aver2,aver3,sum2;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	sum1 = a + b + c + d;
	//printf("%d",sum1);
	sum2 = a + b + c + d;
	aver1 = sum1 / 4;	//2.000000
	aver2 = sum2 / 4;	//2.500000
	aver3 = (float)sum1 / 4;	//2.500000
	printf("%f \t %f \t %f",aver1,aver2,aver3);
	return 0;
}
