#include <stdio.h>
#include <string.h>
int mystrcmp(char *a, char *b){
	for(int i = 0; i < strlen(a) || i < strlen(b); i++){
		if(a[i] > b[i])
			return a[i] - b[i];
		else if(a[i] < b[i])
			return a[i] - b[i];
	}

	return 0;
}
int main(){
	char a[100],b[100];
	scanf("%s %s",a,b);
	int k = mystrcmp(a,b);
	printf("%d\n", k);
	return 0;
}
