#include <stdio.h>
int main(){
	float n;
	scanf("%f", &n);
	float x = n*0.81 - 3500;
	float answer;
	if(x <= 1500){
		answer = x*0.03;
		printf("%.2f\n", answer);
	} 
	else if(x <= 4500){
		answer = x*0.1 -105;
		printf("%.2f\n", answer);
	}
	else if(x <= 9000){
		answer = x*0.2 - 555;
		printf("%.2f\n", answer);
	}
	else if(x <= 35000){
		answer = x*0.25-1005;
		printf("%.2f\n", answer);
	}
	else if(x <= 55000){
		answer = x*0.3 - 2775;
		printf("%.2f\n", answer);
	}
	else if(x <= 80000){
		answer = x*0.35 - 5505;
		printf("%.2f\n", answer);
	}
	else if(x > 80000){
		answer = x*0.45 - 13505;
		printf("%.2f\n", answer);
	}
	return 0;
}

