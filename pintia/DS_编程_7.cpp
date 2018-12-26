#include <cstdio>
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	if(n%5<=3 && n%5>=1)
		printf("Fishing in day %d\n", n);
	else
		printf("Drying in day %d\n", n);
	return 0;
}