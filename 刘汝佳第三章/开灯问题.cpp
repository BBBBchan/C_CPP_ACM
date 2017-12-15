#include <stdio.h>
#define maxn 1500
int a[maxn];
int main()
{
	int n , k;
	scanf("%d %d",&n,&k);
	for(int i = 0;i <= n; i++)
		a[i] = 0;
	for(int j = 1;j <= k; j++){
		for(int count = 1;count*j <= n;count++){		
			if(a[j*count -1] == 0)
				a[j*count -1] = 1;
			else a[j*count -1] =0;
		}
		}
		for(int m = 0;m <= n;m++){
			if(a[m] == 1)
				printf("%d",m+1);
		}
	return 0;
	}

