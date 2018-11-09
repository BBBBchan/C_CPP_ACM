#include <cstdio>
int main(int argc, char const *argv[])
{
	int n,a,b,today=0,all=0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		today = a+b+today-8;
		all+=today;
	}
	printf("%d", all);
	return 0;
}