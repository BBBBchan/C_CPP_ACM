#include <cstdio>
#include <cmath>
int main(int argc, char const *argv[])
{
	int n;
	char c;
	scanf("%d %c", &n, &c);
	int b = sqrt((n+1)/2);
	int ans = n - b*b*2 +1;
	for(int i = 0; i < b; i++){
		for(int j = 0; j < i; j++)
			printf(" ");
		for(int j = 0; j < (b-i)*2-1; j++)
			printf("%c", c);
		printf("\n");
	}
	for(int i = 1; i < b; i++){
		for(int j = 0; j < b-i-1; j++)
			printf(" ");
		for(int j = 0; j < 2*i+1; j++)
			printf("%c", c);
		printf("\n");
	}
	printf("%d", ans);
	return 0;
}