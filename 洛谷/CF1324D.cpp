#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long a[200005], b[200005],c[200005],ans=0;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
		c[i] = a[i]-b[i];
	}
	sort(c, c+n);
	for(int i = 0; i < n; i++){
		long long k = std::upper_bound(c, c+n, -c[i]) - c;
		if(c[i] > 0) ans--;
		ans+=(long long)n-k;
	}
	printf("%lld\n", ans/2);
	return 0;
}