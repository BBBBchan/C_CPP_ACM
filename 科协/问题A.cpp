#include <stdio.h>
#include <stdlib.h>
// int compInc(const void *a, const void *b)  
// {  
//     return *(int *)a - *(int *)b;  
// }  
#define maxn 1050
int a[maxn],b[maxn];
int sum[2];
int main()
{
	int n;
	sum[0] = 0;
	while(scanf("%d",&n) == 1){
		for(int i = 0; i<n;i++)	
			scanf("%d",&a[i]);	//输入每个室友的生命值
		// qsort(a,n,sizeof(a[0]),compInc);
		for(int i = 0;i<n;i++){
			
		}
		sum[1] = 0;
		for(int p = 0;p<n-1;n--)
			{	if(p == n-2){sum[1] += a[0]*a[1]*a[1];break;}
				sum[1] += a[0]*a[1]*a[n-1];
				int q = n;
				for(int i = 0; i<q;i++){
					a[i] =a[i+1];
				}
			}
			if(sum[1] > sum[0])
				sum[0] = sum[1];
		printf("%d",sum[0]);

	}
	return 0;
}