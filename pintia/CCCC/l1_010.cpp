#include <cstdio>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int a[3];
	for(int i = 0; i <3; i++){
		scanf("%d", &a[i]);
	}
	sort(a,a+3);
	printf("%d->%d->%d", a[0], a[1], a[2]);
	return 0;
}