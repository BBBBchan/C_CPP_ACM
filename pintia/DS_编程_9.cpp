#include <cstdio>
int main(int argc, char const *argv[])
{
	long long int a1, b1, a2, b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	long long int ans = a1*b2-a2*b1;
	if(ans < 0)
		printf("%lld/%lld < %lld/%lld\n", a1, b1, a2, b2);
	else if(ans > 0)
		printf("%lld/%lld > %lld/%lld\n", a1, b1, a2, b2);
	else
		printf("%lld/%lld = %lld/%lld\n", a1, b1, a2, b2);
	return 0;
}