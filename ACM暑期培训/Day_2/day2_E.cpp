#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d", &n) != EOF){
		if(n%3==0)
			printf("Cici\n");
		else
			printf("Kiki\n");	
	}
	return 0;
}