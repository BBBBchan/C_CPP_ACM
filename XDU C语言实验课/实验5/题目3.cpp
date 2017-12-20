#include <stdio.h>
#include <string.h>
int main(){
	char a[1000],b[100];
	scanf("%s %s",a,b);
	if(strstr(a,b))
		printf("yes\n");
	else
		printf("no\n");
	return 0;

}