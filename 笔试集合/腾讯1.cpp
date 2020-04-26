#include <cstdio>
struct monster
{
	long long c;
	long long w;
}monsters[1005];
int main(int argc, char const *argv[])
{
	long long n, m, ans1 = 0, ans2 = 0;
	scanf("%lld%lld", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%lld %lld", &monsters[i].c, &monsters[i].w);
		if(monsters[i].c < monsters[i].w*m){
			ans1 += monsters[i].c;
			ans2 += monsters[i].w;
		}
	}
	if(ans1%m == 0)
		ans1/=m;
	else
		ans1 = ans1/m +1;
	printf("%lld\n", ans2-ans1);
	return 0;
}