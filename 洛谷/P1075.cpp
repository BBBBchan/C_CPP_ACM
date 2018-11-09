#include <cstdio>
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 2; i < n; i++)
		if(n%i==0){
			printf("%d", n/i);
			break;
		}
	return 0;
}