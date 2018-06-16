#include <stdio.h>
int cmp ( const void *a , const void *b){
	return *(int *)a - *(int *)b;
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int a[n];
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int ans[n] = {0};
		for(int i = 0; i < n; i++){
			
		}
	}
	return 0;
}