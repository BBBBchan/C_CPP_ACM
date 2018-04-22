#include <stdio.h>
#include <stdlib.h>

int cmp ( const void *a , const void *b)
{
	return *(int *)a - *(int *)b;
}
int main(){
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF){
		int a[n];
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		qsort(a, n, sizeof(int), cmp);
		int num = 1;

		while( ((n+2*num-1)/2 < n) ) {
			if(m >= num)
				m -= num*(a[(n+2*num-1)/2] - a[(n+2*num-3)/2]);					
			if(m <= 0){
				break;
			}
			a[(n-1)/2] += (a[(n+2*num-1)/2] - a[(n+2*num-3)/2]);
			num++;
		}

		a[(n-1)/2] += m / ( (n+2*num-1)/2 - (n-1)/2 );

		printf("%d\n", a[(n-1)/2]);
	}
	return 0;
}