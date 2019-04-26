#include <cstdio>
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--){
		char a[5],b[5];
		scanf("%s %s", a, b);
		long long a1 = 0, b1 = 0;
		a1 += (a[0] << 24);
		a1 += (a[1] << 16);
		a1 += (a[2] << 8);
		a1 += a[3];

		b1 += (b[0] << 24);
		b1 += (b[1]<<16) + (b[2] << 8) + b[3];
		printf("%lld\n", a1+b1);

	}
	return 0;
}