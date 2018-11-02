#include <cstdio>
int main(int argc, char const *argv[])
{
	float a, b;
	scanf("%f %f", &a, &b);
	float x = a + b/10;
	printf("%d\n", (int)(x/1.9));
	return 0;
}