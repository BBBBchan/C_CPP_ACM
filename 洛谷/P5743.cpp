#include <cstdio>
int main(int argc, char const *argv[])
{
	int n, ans= 1;
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		ans+=1;
		ans*=2;
	}
	printf("%d", ans);
	return 0;
}