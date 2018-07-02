#include <stdio.h>
int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	int side1 = m*m - n*n;
	int side2 = 2*m*n;
	int h = m*m + n*n;
	printf("%d %d %d\n", side1, side2, h);
	return 0;
}

