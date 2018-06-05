#include <stdio.h>
int main(){
	int n, count;
	scanf("%d %d", &n, &count);
	int a[n];
	for(int i = 0; i < n; i++){
		a[i] = i+1;
	}
	int i = 0;
	while(a[0]){
		if(n == 0)
			break;
		i = i+count-1;
		while(i>=n)	i = i - n;
		printf("%d ", a[i]);
		a[i] = 0;
		for(int j = i; j<n; j++)
			a[j] = a[j+1];
		n--;
	}
	return 0;
}