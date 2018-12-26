#include <cstdio>
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n, num=0;
		scanf("%d", &n);
		if(n%2 == 0)
			printf("%d\n", n/2);
		else
			printf("%d\n", ((n-3)/2)+1);
	}
	return 0;
}
