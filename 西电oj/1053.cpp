#include <stdio.h>
int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		if(n > 0)
			printf("yes\n");
		else if(n < 0)
			printf("no\n");
		else
			printf("light\n");
	}
}