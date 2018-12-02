#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
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
		else if(y%d != 1 && (n-y)%d != 0){
			printf("-1\n");
			continue;
		}
		else if(y%d == 1 && (n-y)%d != 0){
			printf("%d\n", ((x-1)/d)+1+(y-1)/d);
			continue;
		}
		else if(y%d != 1 && (n-y)%d == 0){
			printf("%d\n", (n-x-1)/d +1 + (n-y)/d);
			continue;
		}
		else{
			printf("%d\n", min((n-1-x)/d+1+(n-y)/d,(x-1)/d+(y-1)/d+1));
			continue;
		}
	}
	return 0;
}