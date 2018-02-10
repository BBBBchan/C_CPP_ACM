#include <stdio.h>
int main(int argc, char const *argv[])
{
	char s[4] = {'a','2','3','4'};
	int k = printf("%d %d %d %d\n", s[0],s[1],s[2],s[3]);
	printf("%d",k);
	//printf("%s\n", s);
	return 0;
}
