#include <stdio.h>
#include <stdlib.h>
struct song
{
	int first;
	int second;
	int distance;
}a[100000];

int cmp(const void *a, const void *b){
      return(*(song *)a).distance > (*(song *)b).distance ? 1 : -1;
}

int main(int argc, char const *argv[])
{
	int n;
	long long int m;
	scanf("%d %I64d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &a[i].first, &a[i].second);
		a[i].distance = a[i].first - a[i].second ;
	}
	qsort(a,n,sizeof(a[0]),cmp);
	long long int sum1=0, sum2=0;
	for(int i = 0; i < n; i++){
		sum1+=a[i].first;
		sum2+=a[i].second;
	}
	if(sum2 > m)
		printf("-1\n");
	else{
		long long int d = sum1 - m;
		int i = 0;
		while(d > 0){
			d -= a[i].distance;
			i++;
		}
		printf("%d\n", i-1);
	}
	return 0;
}