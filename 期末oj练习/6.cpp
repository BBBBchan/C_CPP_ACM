#include <stdio.h>
int F(int x){
	if(x == 0)
		return 7;
	if(x == 1)
		return 11;
	else
		return (F(x-1) + F(x-2));
}
int main(){
	int n, x;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		if(F(x) % 3 == 0)
			printf("yes");
		else
			printf("no");
	}
	return 0;
}