#include <cstdio>
int a[10005];
int main(int argc, char const *argv[])
{
	int n, times = 1, max = 1;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n-1; i++){
		if(a[i] == a[i+1]-1){
			times++;
		}
		else
			times = 1;
		if(times > max)
			max = times;
	}
	printf("%d\n", max);
	return 0;
}