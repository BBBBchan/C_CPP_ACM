#include <cstdio>
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d", &n) != EOF){
		if(n == 0)
			break;
		if(n&1)
			printf("Bob\n");
		else
			printf("Alice\n");
	}
	return 0;
}