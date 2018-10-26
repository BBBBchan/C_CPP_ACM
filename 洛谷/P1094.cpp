#include <cstdio>
#include <algorithm>
using namespace std;
int a[30005];
int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &a[i]);
	}
	sort(a,a+m);
	int i=0,j=m-1,ans = 0;
	while(i<=j){		
		if(a[i]+a[j]<=n){
			j--;
			ans++;
			i++;
		}
		else{
			j--;
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}