#include <stdio.h>
#include <string.h>
int main(){
	char n[100];
	scanf("%s",&n);
	int kase = 1;
	for(int i = 0; i <strlen(n); i++){
		if(n[i] != n[strlen(n)-1-i]){
			kase = 0;
			break;
		}
	}
	if(kase)
		printf("1");
	else
		printf("0");
	return 0;
}
