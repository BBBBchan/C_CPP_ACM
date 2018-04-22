#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		long int x;
		scanf("%ld", &x);
		if(x>100)
			printf("%d\n", x-10);
		else
			printf("91\n");
	}
	return 0;
}