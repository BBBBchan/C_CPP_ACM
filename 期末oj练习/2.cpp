#include <stdio.h>
int main(){
	int n, m,a[10000];
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n-i-1; j++)
			if(a[j] < a[j+1]){
				int k;
				k = a[j];
				a[j] = a[j+1];
				a[j+1] = k;
			}
	if(m > n)
		m = n;
	for(int i = 0; i < m-1; i++)
		printf("%d ",a[i]);
	printf("%d",a[m-1]);
	return 0;
}
