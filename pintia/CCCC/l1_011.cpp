#include <stdio.h>
#include <string.h>
char a[10005], b[10005];
int temp[10005] = {0};
int main(int argc, char const *argv[]){
	gets(a);
	gets(b);
	for(int i = 0; i < strlen(b); i++)
		temp[b[i]] = 1;

	for(int j = 0; j < strlen(a); j++){
		if(temp[a[j]] == 0)
			printf("%c", a[j]);
	}
	return 0;
}