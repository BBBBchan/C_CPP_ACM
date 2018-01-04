#include <stdio.h>
int main(int argc, char const *argv[])
{
	char s[4];
	//printf("%d %d %d %d\n", s[0],s[1],s[2],s[3]);
	scanf("%c,%c,%c",&s[0],&s[1],&s[2]);
	// printf("%d\n", s[1]);
	// printf("%d\n", s[2]);
	// printf("%d\n", s[3]);
	printf("%s\n", s);
	return 0;
}
