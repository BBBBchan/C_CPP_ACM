#include <stdio.h>
int gcd(int x, int y){
	int n = x % y;
	while(n != 0){
		x = y;
		y = n;
		n = x % y; 
	}
	return y;
}
int main(){
	int x,y,m,n;
	scanf("%d %d",&x,&y);
	m = gcd(x,y);
	n = (x * y) / m;
	printf("%d %d\n",m,n);
	return 0;
}