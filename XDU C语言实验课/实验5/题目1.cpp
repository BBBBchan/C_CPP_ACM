#include <stdio.h>
int main()
{
	int a[50];
	int n ;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	for(int i = 0; i < n-1; i++)
		for(int j = 0; j < n-1-i; j++){
			if(a[j] > a[j+1]){
				int k;
				k = a[j+1];	a[j+1] = a[j]; a[j] = k;
			}
		}
	for(int i = 0; i < n;i++)
		printf("%d ",a[i]);
	return 0;
}