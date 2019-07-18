#include <cstdio>
int a[305];
int main(int argc, char const *argv[])
{
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	long long now = 0, now_pos = -1, now_min = 100000002, temp = k, ans = 0;
	for(int j = 0; j < n; j++){
		for(int i = 0; i < temp; i++){
			if(a[i] < now_min){
				now_pos = i;
				now_min = a[i];
			}
		}
		now += now_min;
		ans += now;
		a[now_pos] = 100000001;
		now_min = 100000002;
		if(temp == n)
			continue;
		temp++;
	}
	printf("%lld", ans);
	return 0;
}