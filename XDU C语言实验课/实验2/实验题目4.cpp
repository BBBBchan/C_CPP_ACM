#include <stdio.h>
int main(){
	int n,kase = 1;
	scanf("%d",&n);
	for(int i = 2;i <= n/2;n++){
		if(n%i == 0){
			kase = 0;
			break;
		}
	}
	if(kase){
		printf("yes!\n");
	}
	else 
		printf("no!\n");
	return 0;
}
