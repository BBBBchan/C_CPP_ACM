#include <stdio.h>
int main(int argc, char const *argv[])
{
	printf("%d\n", 1&&2);
	printf("%d\n", 3&&-3);
	printf("%d\n", 0&&-3);
	return 0;
}