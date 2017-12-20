#include <stdio.h>
void turn(int *a,int n){
	for(int i = 0;i < n/2; i++)
	{
		int k = a[n-1-i];		a[n-1-i] = a[i];		a[i] = k;
	}
}
int main()
{	int a[1000];
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	turn(a,n);
	for(int i = 0; i < n; i++)
		printf("%d ",a[i] );
	return 0;
}