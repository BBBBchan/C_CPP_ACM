#include <stdio.h>
int main(int argc, char const *argv[])
{	
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < 1000; i++)
		printf("5");
	printf("\n");
	for(int i = 0; i < 999; i++)
		printf("4");
	printf("5\n");
	return 0;
}