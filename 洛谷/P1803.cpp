#include <cstdio>
#include <algorithm>
using namespace std;
struct work{
	int s;
	int e;
}a[1000008];
bool cmp(work a, work b){
	return a.e<b.e;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &a[i].s, &a[i].e);
	}
	sort(a,a+n,cmp);
	int now = a[0].e , ans = 1;
	for(int i = 1; i < n; i++){
		if(a[i].s<now)
			continue;
		else{
			ans++;
			now = a[i].e;
		}
	}
	printf("%d", ans);
	return 0;
}