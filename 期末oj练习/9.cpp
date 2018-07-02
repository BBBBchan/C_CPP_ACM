#include <stdio.h>
#include <string.h>
int main(){
	char n[10];
	scanf("%s",n);
	int k=0 ;
	for(int i = 0;i < strlen(n); i++){
		k += (n[i] - '0');
	}
	printf("%d\n",k);
	return 0;
}
