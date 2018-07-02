#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
	char n[1000]; 
	int b[1000];
	gets(n);
	int j = 0;
	for(int i = 0; i < strlen(n); i++){
		if(n[i] >= '0' && n[i] <= '9'){
			b[j] = n[i] - '0';
			j++;
		}
	}
	int answer = 0;
	int m = 0;
	for(int i = j; i>0; i--){
		int temp = pow(10.0,i-1);
		temp *= b[m];
		answer+=temp;
		m++;
	}
	printf("%d ",answer);
	double ans = sqrt(answer);
	printf("%.2lf", ans);
	return 0;
}
