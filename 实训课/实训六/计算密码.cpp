#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d %d", &n, &m);
	int ans[n];
	for(int i=0; i<n; i++)
		ans[i] = i+1;
	while(m--){
		int a, b;
		scanf("%d %d",&a,&b);
		int count = 0;
		for(int i = a-1; i < a-1+((b-a)/2+1); i++){
			int temp = ans[i];
			ans[i] = ans[b-1-count];
			ans[b-1-count] = temp;
			count ++;
		}
	}
	for(int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	return 0;
}
