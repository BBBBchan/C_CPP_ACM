#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int a[1005],hole[1005];
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		memset(hole,0,sizeof(hole));
		int j = i;
		hole[j]+= 1;
		while(hole[j]<2){
			j = a[j];
			hole[j]++;
		}
		printf("%d ", j);
	}
	return 0;
}