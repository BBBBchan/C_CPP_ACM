#include <cstdio>
int main(int argc, char const *argv[])
{
	int a[10];
	for(int i = 0; i < 10; i++){
		scanf("%d", &a[i]);
	}
	int n,count=0;
	scanf("%d", &n);
	for(int i = 0; i < 10; i++){
		if(a[i] <= n+30)
			count++;
	}
	printf("%d\n", count);
	return 0;
}