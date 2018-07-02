#include <stdio.h>
int main(){
	char a[1000], b[1000],c[1000];
	scanf("%s",a);
	scanf("%s",b);
	int i = 0;
	while(a[i] == b[i]){
		c[i] = a[i];
		i++;
	}
	for(int j = 0; j < i; j++)
		printf("%c",c[j]);
	return 0;
} 
