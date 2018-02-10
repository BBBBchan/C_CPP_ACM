#include <stdio.h>
int main(){
	int n, x;
	float sum = 0.0;
	float average = 0.0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		sum += x;
	}
	average = sum / n ;
	printf("%.2f\n", average);
	return 0;
}