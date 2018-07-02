#include <stdio.h>
#include <math.h>
int main(){
	double x,answer = 1;
	int n = 1,kase;
	scanf("%lf",&x);
	while(true){
		if(n%2 == 1)
			kase = -1;
		else
			kase = 1; 
		double temp = pow(x,2*n);
		for(int i = 1; i <= 2*n; i++){
			temp /= i;
		}
		answer += kase*temp;
		if(temp <= 0.000001)
			break;
		n++;
	}
	printf("%.6lf", answer);
	return 0;
}
