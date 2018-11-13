#include <cstdio>
#include <cstdlib>
long long int a[10050];
int main(int argc, char const *argv[])
{
	long long int n;
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	long long int m, p1, s1, s2,p2,min;
	scanf("%lld %lld %lld %lld", &m, &p1, &s1, &s2);
	a[p1] += s1;
	long long ans1 = 0, ans2 = 0;
	for(int i = 1; i < m; i++){
		ans1 += a[i]*(m-i);
	}
	for(int i = m+1; i <= n; i++){
		ans2 += a[i]*(i-m);
	}
	min = abs(ans1-ans2);
	p2 = m;
	for(int i = 1; i <= n; i++){
		if(i<m){
			ans1+=s2*(m-i);
			if(abs(ans1-ans2)<min){
				p2 = i;
				min = abs(ans1-ans2);
			}
			ans1 -= s2*(m-i);
		}
		else if(i > m){
			ans2 += s2*(i-m);
			if(abs(ans1-ans2)<min){
				p2 = i;
				min = abs(ans1-ans2);
				ans2-=s2*(i-m);
			}
		}
	}
	printf("%lld\n", p2);
	return 0;
}