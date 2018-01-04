#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{	int m;
	scanf("%d" , &m);
	for(int i = 0; i < argc; i++)
		printf("%s\n",argv[i] );
	return 0;
}