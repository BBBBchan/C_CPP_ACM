#include <stdio.h>
#include <string.h>
char a[1000];
int main(){
	scanf("%s",a);
	int k = strlen(a);
	for(int i = k-1; i >= 0; i--)
		printf("%c",a[i] );
	return 0;
}
