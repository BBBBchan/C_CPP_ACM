#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		int q;
		scanf("%d", &q);
		printf("%d\n", q*(q-1)/2);
	}
	return 0;
}