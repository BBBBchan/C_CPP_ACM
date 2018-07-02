#include <stdio.h>
#include <string.h>
int main(){
	char a[50], b[256],c[50];
	gets(a);
	gets(b);
	int k = 0;
	for(int i = 0; i < strlen(b);i+=2){
		for(int j = 0; j < strlen(a); j++)
			if(b[i] == a[j]){
				c[k]=b[i];
				k++;
			}		
	}
	for(int i = 0; i < k-1; i++)
		for(int j = 0; j < k-i-1; j++)
			if(c[j] > c[j+1]){
				int m = c[j];
				c[j] = c[j+1];
				c[j+1] = m;
			}
	if(strlen(c) == 0)
		printf("No");
	else{
	int p = 1;
	for(int i = 1; i < k; i++)
		if(c[i] != c[i-1]){
			c[p++] = c[i];
		}
	for(int i = 0; i < p-1; i++)
		printf("%c ",c[i]);
	printf("%c",c[p-1]);
}
	return 0;
	
}
