#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int a[n+1],b[n+1];
	a[0] = 1;
	a[1] = 1;
	b[0] = 1;
	if(n == 1)
		printf("1");
	else if(n >= 2)
		printf("1\n1 1\n");
	for(int i = 2; i < n; i++){
		int j;
		for(j = 1; j < i; j++){
			b[j] = a[j] + a[j-1];
		}
		b[j] = 1;
		for(j = 0; j <= i; j++){
			printf("%d ", b[j]);
		}
		printf("\n");
		for(j = 0; j < n+1; j++){
			a[j] = b[j];
		}
	}
	return 0;
} 
