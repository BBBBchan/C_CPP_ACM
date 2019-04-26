#include <cstdio>
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	while(n--){
		int m;
		scanf("%d", &m);
		if(m & 1)
			printf("zs wins\n");
		else
			printf("pb wins\n");
	}
	return 0;
}