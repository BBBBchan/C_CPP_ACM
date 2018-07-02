#include <stdio.h>
#include <math.h>
int main(){
	float x ,answer, pi = acos(-1.0);
	scanf("%f", &x);
	if(x>=0 && x< 10){
		answer = 2*cos((x/180)*pi+ pi/6);
		printf("%.2f\n",answer);
	}
	else if(x>=10 && x < 30){
		answer = sqrt(4.1+5*x*x);
		printf("%.2f\n", answer);
	}
	else if(x>=30 && x<50){
	
		answer = 1.75*(x-3.0)+45;
		printf("%.2f\n", answer);
	}	
	else
		printf("ÊäÈë´íÎó\n");
	
	return 0;
	}

