#include <cstdio>
#include <algorithm>
using namespace std;
struct que{
	int time;
	int num;
}a[1010];
bool cmp(que a, que b){
	return a.time<b.time;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i].time);
		a[i].num = i+1;
	}
	sort(a,a+n,cmp);
	for(int i = 0; i < n; i++){
		printf("%d ", a[i].num);
	}
	printf("\n");
	double ans = 0;
	for(int i = 0; i < n; i++){
		ans += a[i].time * (n-1-i);
	}
	printf("%.2f", ans/n);
	return 0;
}