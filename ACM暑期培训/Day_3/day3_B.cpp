#include <stdio.h>
int main(int argc, char const *argv[])
{	int a[450];
	int n, k;
	while(scanf("%d %d", &n, &k) != EOF){
		int count = 1;
		for(int i = k; i <= n; i++)
			a[i] = i;
		for(int i = 0; i < k; i++){
			for(int j = 2; j*j < i; j++){
				if(a[n-i]%j == 0){
					count++;
					for(int m = i; m < k; m++){
						while(a[n-m]%i==0)
							a[n-m]/=i;
					}
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}