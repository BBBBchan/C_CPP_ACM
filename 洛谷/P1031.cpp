#include <cstdio>
int a[10005];
int main(int argc, char const *argv[])
{
	int n,sum = 0, aver,ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		sum+=a[i];
	}
	aver = sum/n;
	for(int i = 0; i < n-1; i++){
		if(a[i]!=aver){
			a[i+1] += a[i]-aver;
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}