#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		long long int T;
		scanf("%d %lld", &n, &T);
		int a[n];
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a,a+n);
		int k;
		for(k = 2; k <= n; k++){
			int times = ceil((float)(n-1)/(float)(k-1));
			long long int ans=times*a[0];
			for(int i = 1; i < n; i+=k-1){
				long long int temp = 0;
				for(int j  = 0; j < k-1 && i+j < n; j++)
					temp += a[i+j];
				ans += times*temp;
				times--;
			}
			if(ans <= T)
				break;
		}
		printf("%d\n", k);
	}
	return 0;
}
