#include <stdio.h>
#include <string.h>
int main(){
	char a[100];
	while(scanf("%s", &a) != EOF){
		int b = strlen(a);
		for(int i = 0; i < strlen(a)-3; i++)
			printf("%c",a[i]);
		printf(".");
		if(a[b-1] >= '5')
			while(a[b-i] = 0)
		else
			printf("%c",a[b-2]);
		printf("\n");
	}
	return 0;
}
