#include <cstdio>
#include <cstdlib>
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n, x, y, d;
		scanf("%d %d %d %d", &n, &x, &y, &d);
		if(abs(y-x) % d == 0){
			printf("%d\n", abs(y-x)/d);
			continue;
		}
		else if(y%d != 1 && (n-y)%d != 1){
			printf("-1\n");
			continue;
		}
		else if(x > n-x){
			printf("%d\n", (n-x)/d + (n-y)/d);
			continue;
		}
		else
			printf("%d\n", x/d+y/d);
	}
	return 0;
}