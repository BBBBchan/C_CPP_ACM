#include <cstdio>
int main(int argc, char const *argv[])
{
	int a1, b1, c1;
	int a2, b2, c2;
	scanf("%d:%d:%d", &a1, &b1, &c1);
	scanf("%d:%d:%d", &a2, &b2, &c2);
	int n;
	scanf("%d", &n);
	long long ans = 0;
	ans += 3600*(a2-a1);
	ans += 60*(b2-b1);
	ans += (c2-c1);
	ans *= n;
	printf("%lld\n", ans);
	return 0;
}