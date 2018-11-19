#include <cstdio>
int x[10005];
int main(int argc, char const *argv[])
{
	int l ,m,ans = 0;
	scanf("%d %d", &l, &m);
	for(int i = 0; i <= l; i++)
		x[i] = 1;
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		for(int j = a; j <= b; j++)
			x[j] = 0;
	}
	for(int i = 0; i <= l; i++){
		if(x[i] == 1)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}