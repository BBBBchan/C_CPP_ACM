
#include <stdio.h>
int main(int argc, char const *argv[])
{	int a[450];
	int n, k;
	while(scanf("%d %d", &n, &k) != EOF){
		int count = 1;
		for(int i = n; i > n-k; i--)
			a[i] = i;
		for(int i = 0; i < k; i++){
			for(int j = 2; j*j <= a[n-i]; j++){
				if(a[n-i]%j == 0){
					count++;
					for(int m = i; m < k; m++){
						while( a[n-m] % j == 0){
							a[n-m]= a[n-m]/j;
						}
					}
				}
			}
		}
		for(int i = n; i > n-k; i--){
			if(a[i]>1)
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}
