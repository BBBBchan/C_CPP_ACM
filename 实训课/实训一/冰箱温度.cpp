#include <stdio.h>
int main(){
	float hour;
	float minute;
	scanf("%f %f", &hour, &minute);
	float t = (hour + (minute/60.0));
	float T = ((4*t*t)/(t+2) - 20);
	printf("%.2f", T);
	return 0;
}

