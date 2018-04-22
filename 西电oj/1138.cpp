#include <stdio.h>
int main(){
	int a1,a2,b1,b2;
	while(scanf("%d+%di %d+%di", &a1, &b1, &a2, &b2) != EOF){
		int a3 = a1+a2;
		int b3 = b1+b2;
		printf("%d+%di\n", a3, b3);
	}
	return 0;
}