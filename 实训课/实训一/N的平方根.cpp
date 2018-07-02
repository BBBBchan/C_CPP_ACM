#include <stdio.h>
int main(){
	float n;
	scanf("%f",&n);
	float LG = 1.0;
	float NG = 0.5*(LG + n/LG);
	while( (NG-LG) >= 0.005 || (NG-LG) <= -0.005){
		LG = NG;
		NG = 0.5*(LG + n/LG);
	}
	printf("%.2f", NG);
	return 0;
}

