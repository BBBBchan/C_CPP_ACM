#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a, b;
	while(scanf("%d %d", &a, &b) != EOF){
		int c = a+b;
		printf("%d\n",c);
	}
	return 0;
}