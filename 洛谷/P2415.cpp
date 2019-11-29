#include <cstdio>
int main(int argc, char const *argv[])
{
	int s,coun = 0;
	long long sum = 0;
	while(~scanf("%d", &s)){
		coun++;
		sum += s;
	}
	sum = (sum<<(coun-1));
	printf("%lld\n", sum);
	return 0;
}