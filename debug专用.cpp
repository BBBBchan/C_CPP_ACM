#include <cstdio>
char a[1000005],z;
int b[1000005];
int main(int argc, char const *argv[])
{
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d %c", &n, &z);
		scanf("%s", a);
		for(int i = 0; i < n; i++)
			b[i] = (int)z-a[i];
		for(int i = 0; i < n; i++)
			printf("%d ", b[i]);
	}
	return 0;
}
