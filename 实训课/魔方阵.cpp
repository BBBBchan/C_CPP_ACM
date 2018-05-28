#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int a[n][n];
	a[0][n/2] = 1;
	int temp1 = 0, temp2 = n/2;
	for(int i = 2; i <= n*n; i++){
		if(((i-1) % n) == 0 && (temp1+1 < n)){
			a[temp1+1][temp2] = i;
			temp1++;
		}
		else if(i-1%n == 0 && temp1+1 >= n){
			a[0][temp2] = i;
			temp1 = 0;
		}
		else{
			temp1--;
			temp2++;
			if(temp1 == n)
				temp1 = 0;
			else if(temp1 < 0)
				temp1 = n-1; 
			if(temp2 == n)
				temp2 = 0;
			a[temp1][temp2] = i;
		}
	} 
	for(int i = 0; i < n;  i++){
		for(int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}
