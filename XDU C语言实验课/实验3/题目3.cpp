#include <stdio.h>
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int count = n;
	for(int i = 1;i <= n;i++){
		for(int x = count;x>0;x--){
			printf(" ");
		}
		for(int x = 1;x<=2*i-1;x++){
			printf("*");
		}
		for(int x = 0;x<m;x++){
			printf(" ");
		}
		for(int x = 2*count-1;x>=1;x--){
			printf("*");
		}
	printf("\n");	
	count--;
	}
	return 0;
}
