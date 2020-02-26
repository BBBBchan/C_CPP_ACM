#include <cstdio>
long long sum[4000005], a[4000005];
long long n,m;
long long nowbig = -1, ansl = 4000006, ansr = 1000000007;
int main(int argc, char const *argv[])
{
	scanf("%lld %lld", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}
	sum[0] = 0;
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1]+a[i-1];
	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	printf("%lld ", sum[i]);
	// }
	// printf("\n");
	for(int i = 1; i <= n; i++){
		long long left = 0, right = i;
		while(right >left){
			long long mid = left+(right-left)/2;
			// printf("%d %lld\n", i, mid);
			if(sum[i] - sum[mid] > m){
				left = mid+1;
			}
			else{
				if((sum[i] - sum[mid] > nowbig) || (sum[i] - sum[mid] == nowbig && left < ansl)){
					nowbig = sum[i] - sum[mid];
					// printf("here%d %lld %lld\n", i, sum[i], sum[mid]);
					ansl = mid;
					ansr = i;
				}
				right = mid;
			}
		}
		// printf("%lld %lld %lld\n", ansl, ansr, nowbig );
	}
	printf("%lld %lld %lld", ansl+1, ansr, nowbig);
	return 0;
}