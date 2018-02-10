#include <stdio.h>
int main(){
	float a;
	scanf("%f",&a);
	if(a >= 0.0 && a <= 110.0)
		printf("%.2f\n",a * 0.5 );
	else if(a <= 210.0)
		printf("%.2f\n", 55.0 + (a-110.0)*0.55);
	else if(a > 210.0)
		printf("%.2f\n",55.0 + 55.0 + (a - 210.0) * 0.70);
	return 0;
}