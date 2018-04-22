#include <stdio.h>
int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		n-=10;
		printf("%d\n", n);
	}
	return 0;
}