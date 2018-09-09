#include <cstdio>
#include <cmath>
using namespace std;
char a[1000005],z;
int main(int argc, char const *argv[])
{
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d %c", &n, &z);
		scanf("%s", a);
		int i = 0;
		while(a[i]==z){
			n--;
			i++;
		}
		if(abs((int)z - a[i]) < 10)
			printf("%d\n", 2*n-1);
		else if(n == 0)
			printf("1\n");
		else
			printf("%d\n", 2*n);
	}
	return 0;
}