#include <cstdio>
int joseph(int n, int m){
	int ans = 0;
	for(int i = 2; i <=n; i++){
		ans = (ans+m)%i;
	}
	return ans+1;
}
int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d",  &n, &m);
	int ans = joseph(n,m);
	printf("%d\n", ans);
	return 0;
}