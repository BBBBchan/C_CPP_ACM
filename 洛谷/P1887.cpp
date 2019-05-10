#include <cstdio>
int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	if(n%m == 0){
		for(int i = 0; i < m-1; i++)
			printf("%d ", n/m);
		printf("%d", n/m);
	}
	else{
		for(int i = 0; i < m-(n%m); i++)
			printf("%d ", n/m);
		for(int i = 0; i < n%m-1; i++)
			printf("%d ", n/m+1);
		printf("%d", n/m+1);
	}
	return 0;
}