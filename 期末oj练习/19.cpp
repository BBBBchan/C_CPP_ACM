#include <stdio.h>
int main(){
	char a = 'a';
	for(int i = 0; i < 26; i++)
		printf("%c ",a+i);
	printf("\n");
	a = 'z';
	for(int i = 0; i < 26; i++)
		printf("%c ",a-i);
	return 0;
	
}
