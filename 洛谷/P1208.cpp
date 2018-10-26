#include <cstdio>
#include <algorithm>
using namespace std;
struct sold{
	int num;
	int money;
}milk[5005];
bool cmp(sold a, sold b){
	return a.money<b.money;
}
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &milk[i].money, &milk[i].num);
	}
	sort(milk, milk+m, cmp);
	int ans = 0,all=0,i=0;
	while(all<n){
		all+=milk[i].num;
		ans+=milk[i].num*milk[i].money;
		i++;
	}
	ans -=(all-n)*milk[--i].money;
	printf("%d", ans);
	return 0;
}