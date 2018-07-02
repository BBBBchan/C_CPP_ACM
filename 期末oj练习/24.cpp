#include <stdio.h>
int main(){
	int n,k;
	scanf("%d",&n);
	float sum = 0;
	for(int i = 0; i < n; i++){
		scanf("%d",&k);
		sum += k;
	}
	float average;
	average = sum / n;
	printf("%.2f",average);
	return 0;
}
